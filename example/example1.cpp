// Copyright Dmitry Goncharov 2009
// Use, modification, and distribution is subject to the BSD license
// http://www.opensource.org/licenses/bsd-license.php

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <boost/lexical_cast.hpp>
#include <backtrace/backtrace.hpp>

using std::cout;
using std::endl;

void print_bt(void)
{
    typedef std::vector<void*> backtrace_t;
    typedef std::vector<std::string> symbols_t;

    cout << "addresses:\n" << endl;
    backtrace_t const bt = btrace::backtrace(100);
    std::copy(bt.begin(), bt.end(), std::ostream_iterator<void*>(cout, "\n"));

    cout << "symbols:\n" << endl;
    symbols_t const sym = btrace::symbols(bt);
    std::copy(sym.begin(), sym.end(), std::ostream_iterator<std::string>(cout, "\n"));

    cout << "demangled:\n" << endl;
    symbols_t const demangled = btrace::demangle(sym);
    std::copy(demangled.begin(), demangled.end(), std::ostream_iterator<std::string>(cout, "\n"));
}

void f(int ncalls)
{
    if (ncalls > 1)
        f(ncalls - 1);
    else
        print_bt();
}

int main(int argc, char const* argv[])
{
    if (argc != 2)
    {
        std::cerr << "usage: " << argv[0] << " ncalls" << endl;
        return 1;
    }

    int const d = boost::lexical_cast<int>(argv[1]);
    f(d);

    return 0;
}

