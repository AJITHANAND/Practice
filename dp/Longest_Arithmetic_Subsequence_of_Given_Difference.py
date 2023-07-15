import collections
from typing import *
class Solution:
    def longestSubsequence(self, arr: List[int], difference: int) -> int:
        seen = collections.Counter()
        for num in arr:
            seen[num] = seen[num - difference] +1
        return max(seen.values())


def main():
    arr = [1,5,7,8,5,3,4,2,1]
    diff = -2
    s = Solution()
    print(s.longestSubsequence(arr=arr,difference=diff))

if __name__ == "__main__":
    main()