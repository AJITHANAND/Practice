nums = [1,2,3]
# Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


def permute(nums):
    solution = []
    perms = []
    def backtrack():
        if len(perms) == len(nums):
            solution.append(perms[:])
            return
        else:
            for num in nums:
                if num not in perms:
                    perms.append(num)
                    backtrack()
                    perms.pop()
    backtrack()
    return solution
print(permute(nums))