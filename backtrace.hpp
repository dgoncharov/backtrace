#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP

// Copyright Dmitry Goncharov 2009
// Use, modification, and distribution is subject to the BSD license
// http://www.opensource.org/licenses/bsd-license.php

#include <vector>
#include <string>

namespace callstack
{
std::vector<void*> backtrace(int depth);
std::vector<std::string> symbols(std::vector<void*> const& bt);
std::vector<std::string> demangle(std::vector<std::string> const& bt);
} // namespace callstack

#endif // BACKTRACE_HPP

