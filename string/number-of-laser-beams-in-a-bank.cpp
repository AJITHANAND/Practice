#include <iostream>
#include <vector>
using namespace std;

class Solution {

#ifdef __AVX2__
#include <immintrin.h>
  size_t countLasers(const char *str, size_t len) {
    size_t count = 0;
    const char *ptr = str;

    if (len >= 32) {
      __m256i ones = _mm256_set1_epi8('1');
      size_t simd_len = len - (len % 32);

      for (size_t i = 0; i < simd_len; i += 32) {
        __m256i data = _mm256_loadu_si256((__m256i *)(ptr + i));
        __m256i cmp = _mm256_cmpeq_epi8(data, ones);
        int mask = _mm256_movemask_epi8(cmp);
        count += __builtin_popcount(mask);
      }
      ptr += simd_len;
      len -= simd_len;
    }

    for (size_t i = 0; i < len; i++) {
      count += (ptr[i] == '1');
    }

    return count;
  }

#elif defined(__ARM_NEON)
#include <arm_neon.h>
  size_t countLasers(const char *str, size_t len) {
    size_t count = 0;
    const char *ptr = str;

    if (len >= 16) {
      uint8x16_t ones = vdupq_n_u8('1');
      size_t simd_len = len - (len % 16);

      for (size_t i = 0; i < simd_len; i += 16) {
        uint8x16_t data = vld1q_u8((uint8_t *)(ptr + i));
        uint8x16_t cmp = vceqq_u8(data, ones);

        uint8x8_t low = vget_low_u8(cmp);
        uint8x8_t high = vget_high_u8(cmp);

        count -= vaddlv_u8(low);
        count -= vaddlv_u8(high);
      }
      ptr += simd_len;
      len -= simd_len;
    }

    for (size_t i = 0; i < len; i++) {
      count += (ptr[i] == '1');
    }

    return count;
}
#else
  size_t countLasers(const char *s, size_t len) {
    size_t count = 0;
    size_t end = len, start = 0;
    while (start + 8 < end) {
      count += (s[start] == '1') + (s[start + 1] == '1') +
               (s[start + 2] == '1') + (s[start + 3] == '1') +
               (s[start + 4] == '1') + (s[start + 5] == '1') +
               (s[start + 6] == '1') + (s[start + 7] == '1');
      start += 8;
    }
    while (start < end) {
      count += (s[start] == '1');
      start++;
    }
    return count;
  }
#endif

public:
  int numberOfBeams(vector<string> &bank) {
    size_t prev_count = countLasers(bank[0].c_str(), bank[0].size());
    size_t total_beams = 0;
    for (size_t i = 1; i < bank.size(); i++) {
      size_t curr_count = countLasers(bank[i].c_str(), bank[i].size());
      if (curr_count > 0) {
        total_beams += prev_count * curr_count;
        prev_count = curr_count;
      }
    }
    return total_beams;
  }
};

static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();

int main() {
  Solution sol;
  vector<string> bank = {"011001", "000000", "010100", "001000"};
  cout << sol.numberOfBeams(bank) << endl; // Output: 8
  return 0;
}