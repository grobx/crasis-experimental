//
// length.hpp
// ~~~~~~~~~~
//
// Copyright (c) 2017 Giuseppe Roberti (gr at silenti dot net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CRASIS__EXPERIMENTAL__LENGTH_HPP
#define CRASIS__EXPERIMENTAL__LENGTH_HPP

namespace crasis {
namespace experimental {

constexpr std::size_t length(const char* str)
{
  return (*str == 0) ? 0 : length(str + 1) + 1;
}

}
}

#endif // CRASIS__EXPERIMENTAL__LENGTH_HPP
