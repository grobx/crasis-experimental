#include "doctest.h"
#include "crasis/experimental/is.hpp"

#include <set>

using namespace crasis::experimental;

// alphabet definitions
constexpr char sparse[] = "012349AEFGJUZdeiquz";
using sparse_seq = seq<sparse>;
using sparse_alphabet = check_sparse<sparse_seq>;

TEST_CASE("is in a sparse alphabet") {

  for (char c = 0; c < std::numeric_limits<char>::max(); ++c) {
    if (std::binary_search(sparse,
                           sparse + length(sparse),
                           c)) {
      CHECK(is<sparse_alphabet>(c));
    } else {
      CHECK_FALSE(is<sparse_alphabet>(c));
    }
  }
}
