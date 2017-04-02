#include "doctest.h"
#include "crasis/experimental/is.hpp"

using namespace crasis::experimental;

// only for testing
constexpr char a_to_z[] = "abcdefghijklmnopqrstuvwxyz";

// alphabet definitions
using a_to_z_range_alphabet = check_range<'a', 'z'>;

TEST_CASE("is in a range alphabet") {

  for (char c = 0; c < std::numeric_limits<char>::max(); ++c) {
    if (std::binary_search(a_to_z, a_to_z + length(a_to_z), c)) {
      CHECK((is<a_to_z_range_alphabet>(c)));
    } else {
      CHECK_FALSE((is<a_to_z_range_alphabet>(c)));
    }
  }
}
