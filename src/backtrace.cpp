// Copyright Dmitry Goncharov 2009
// Use, modification, and distribution is subject to the BSD license
// http://www.opensource.org/licenses/bsd-license.php

#ifdef unix
#include <unistd.h>
#endif
#ifdef __GLIBC__
#include <execinfo.h>
#endif
#ifdef __GNUC__
#include <cxxabi.h>
#endif
#include <string>
#include <vector>
#include <algorithm>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <boost/regex.hpp>
#include <backtrace.hpp>

namespace callstack
{
using std::vector;
using std::string;

vector<void*> backtrace(int depth)
{
    vector<void*> bt(depth);
#ifdef __GLIBC__
    int const n = ::backtrace(&bt[0], bt.size());
    bt.resize(n);
#endif
    return bt;
}

vector<string> symbols(vector<void*> const& bt)
{
    vector<string> result;
#ifdef __GLIBC__
    char** s = ::backtrace_symbols(&bt[0], bt.size());
    if (s)
    {
        boost::shared_ptr<void> d(static_cast<void*>(0), boost::bind(free, s));
        result.reserve(bt.size());
        std::copy(s, s + bt.size(), std::back_inserter(result));
    }
#endif
    return result;
}

vector<string> demangle(vector<string> const& bt)
{
    vector<string> result;
#ifdef __GNUC__
    for (vector<string>::const_iterator it = bt.begin(), last = bt.end(); it != last; ++it)
    {
        boost::regex e("\\((.+)\\+0x[0-9A-Fa-f]+\\)");
        boost::cmatch m;
        bool const ok = boost::regex_search((*it).c_str(), m, e, boost::match_default);
        if (ok && m[1].matched)
        {
            string const s = m[1]; //TODO; get rid of the temp var
            int status = -1;
            //TODO; pass buf to __cxa_demangle()?
            char* c = abi::__cxa_demangle(s.c_str(), 0, 0, &status);
            boost::shared_ptr<void> d(static_cast<void*>(0), boost::bind(free, c));
            if (0 == status && c)
                result.push_back(c);
            else
                result.push_back(s); // This must be a C function which has never been mangled.
            continue;
        }
        // Could not find the name of a function.
        // Push back the address.
        result.push_back(*it);
    }
#endif
    return result;
}
} // namespace callstack

