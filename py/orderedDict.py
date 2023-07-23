from collections import OrderedDict

dictionary =  OrderedDict()

for _ in range(int(input())):
    temp = list(map(str,input().split()))
    key,val = " ".join(temp[0:-1]),int(temp[-1])
    dictionary[key] = dictionary.get(key,0) + int(val)

for key in dictionary.keys():
    print(key,dictionary[key],sep=' ')
