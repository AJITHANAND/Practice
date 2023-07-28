# https://www.hackerrank.com/challenges/py-set-mutations/problem


n = int(input())
set1 = set(map(int,input().split()))
for _ in range(int(input())):
    cmnd , num = input().split()
    temp = set(map(int,input().split()))
    getattr(set1,cmnd)(temp)
    
print(sum(set1))
