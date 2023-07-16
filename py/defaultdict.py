from collections import defaultdict

n,m = map(int,input().split())
store = defaultdict(list,)

i =1
for _ in range(n):
    temp = input()
    store[temp].append(i)
    i+=1

for _ in range(m):
    temp = input()
    arr = list(store[temp])
    print("-1" if len(arr)==0 else (' '.join(str(i) for i in arr)))