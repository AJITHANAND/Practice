from collections import deque
no = int(input())
d = deque()
for i in range(no):
        name,*no = input().split()
        eval('d.{}({})'.format(name,str(*no)))
print(*d)