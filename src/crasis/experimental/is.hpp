//
// is.hpp
// ~~~~~~
//
// Copyright (c) 2017 Giuseppe Roberti (gr at silenti dot net)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CRASIS__EXPERIMENTAL__IS_HPP
#define CRASIS__EXPERIMENTAL__IS_HPP

#include <algorithm>
#include "length.hpp"

namespace crasis {
namespace experimental {

// B must be less than E
template <const char B, const char E> struct check_range {
  const char b = B;

  const char e = E;

  const bool is(const char c) { return c >= b && c <= e; }
};

// S must be a seq<alphabet>
template <typename S> struct check_sparse {
  S s;

  const bool is(const char c) {
    //return std::binary_search(s.a, s.a + s.l, c);

    return std::find(s.a, s.a + s.l, c) != s.a + s.l;
  }
};

// A must be sorted
template <const char A []> struct seq {
  const char * a = A;

  const std::size_t l = length(A);
};

// C must be either check_range or check_sparse
template <typename C> int is(const char c) {
  return C().is(c);
}

}
}

#endif // CRASIS__EXPERIMENTAL__IS_HPP
