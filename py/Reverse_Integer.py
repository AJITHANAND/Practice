class Solution:
    def reverse(self, x: int) -> int:
        stat = -1 if x <0 else 1
        result = int(str(x*stat)[::-1]) * stat
        return  result if result.bit_length() < 32 else 0

if __name__ == '__main__':
    st = Solution()
    print(st.reverse(-123))
    print(st.reverse(1534236469))