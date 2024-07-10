class Solution:
    def minOperations(self, logs: List[str]) -> int:
        count = 0 
        for i in logs:
            if i == "../":
                if count >0:
                    count -=1
                else:
                    count=0
            elif i != "./":
                count+=1
        return count if count>=0 else 0
