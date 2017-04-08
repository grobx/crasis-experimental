#include "benchmark/benchmark.h"
#include "crasis/experimental/is.hpp"

#include <cassert>
#include <cstring>
#include <exception>
#include <iostream>
#include <string>

using namespace crasis::experimental;

// range distance must be 95
const char range_start = '\x10', range_end = '\x6f';

// fake_alnum must be 95 chars long, and sorted (for binary search benchmarks)
constexpr char fake_alnum[] = "\x10\x12\x14\x16\x18\x1a\x1c\x1e"
                              "\x20\x22\x24\x26\x28\x2a\x2c\x2e"
                              "\x30\x32\x34\x36\x38\x3a\x3c\x3e"
                              "\x40\x42\x44\x46\x48\x4a\x4c\x4e"
                              "\x50\x52\x54\x56\x58\x5a\x5c\x5e"
                              "\x60\x62\x64\x66\x68\x6a\x6c\x6e"
                              "\x70\x72\x74\x76\x78\x7a\x7c\x7e"
                              "\x80\x82\x84\x86\x88\x8a\x8c\x8e"
                              "\x90\x92\x94\x96\x98\x9a\x9c\x9e"
                              "\xA0\xA2\xA4\xA6\xA8\xAa\xAc\xAe"
                              "\xB0\xB2\xB4\xB6\xB8\xBa\xBc\xBe"
                              "\xC0\xC2\xC4\xC6\xC8\xCa\xCc"
    ;

static void BM_StdFind(benchmark::State &state) {
  bool ret;

  while (state.KeepRunning()) {
    auto fake_alnum_length = std::strlen(fake_alnum);

    auto pos = std::find(fake_alnum, fake_alnum + fake_alnum_length, '\xCd');

    ret = pos != fake_alnum + fake_alnum_length;
  }
}
BENCHMARK(BM_StdFind);

static void BM_StdBinarySearch(benchmark::State &state) {
  bool ret;

  while (state.KeepRunning()) {
    auto fake_alnum_length = std::strlen(fake_alnum);

    ret = std::binary_search(fake_alnum, fake_alnum + fake_alnum_length, '\xCd');
  }
}
BENCHMARK(BM_StdBinarySearch);

static void BM_ForEach(benchmark::State &state) {
  bool ret;

  while (state.KeepRunning()) {
    auto fake_alnum_length = std::strlen(fake_alnum);

    for(int i = 0; i < fake_alnum_length; ++i) {
      if (fake_alnum[i] == '\xCd') {
        ret = true;
        break;
      }
    }

    ret = false;
  }
}
BENCHMARK(BM_ForEach);

/// SPARSE LINEAR BENCHMARK
using alnum_seq = seq<fake_alnum>;
using alnum_sparse_linear_check = check_sparse<alnum_seq>;

static void BM_SparseLinear(benchmark::State &state) {
  while (state.KeepRunning())
    is<alnum_sparse_linear_check>('\xCd');
}
BENCHMARK(BM_SparseLinear);

/// SPARSE BINARY BENCHMARK
using alnum_sparse_binary_check = check_sparse_binary<alnum_seq>;

static void BM_SparseBinary(benchmark::State &state) {
  while (state.KeepRunning())
    is<alnum_sparse_binary_check>('\xCd');
}
BENCHMARK(BM_SparseBinary);

/// ALNUM RANGE BENCHMARK
using alnum_range_check = check_range<range_start, range_end>;

static void BM_Range(benchmark::State &state) {
  while (state.KeepRunning())
    is<alnum_range_check>('\x70');
}
BENCHMARK(BM_Range);

BENCHMARK_MAIN()
