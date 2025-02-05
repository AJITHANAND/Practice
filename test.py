def mergeSort(arr:list)->list:
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = mergeSort(arr[:mid])
    right = mergeSort(arr[mid:])
    return merge(left,right)

def merge(left:list,right:list)->list:
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    while i < len(left):
        result.append(left[i])
        i += 1
    while j < len(right):
        result.append(right[j])
        j += 1
    return result





arr = [5,4,3,2,1]
print(mergeSort(arr))





# def TwoSum(arr:list,target)->bool:
#     first = 0
#     last = len(arr) -1

#     while first < last:
#         sum = arr[first] + arr[last]
#         if sum == target:
#             return True
#         elif sum > target:
#             last -=1
#         else:
#             first +=1
#     return False

# # TWO POINTER APPROACH 

# #      first + last : medium sum 
#     # find sum : 9
#     # sum  first + last : 17 , 17 > target : last - 1
#     # sum  first + last-1 : 13  , 13  >9  : last -1
#     # sum first + last-1 : 9 , 9 ==  9 , return true 

#     # find sum : 26
#     # sum  first + last : 17  , 17 < 26 , first  +1
#     # sum  first +1  +  last : 22 , 22<26  first + 1
#     # sum  first +1  + last :26 , 26 == 26 , return true

#     # find sum : 14
#     # sum  first + last : 17  , 17 > 14 , last -1
#     # sum  first + last-1 :13 ,  13 <14 , first +1
#     # sum  first +1   + last -1 :  18 > 14 ,(first > last) return false

# arr = [2,7,11,15]   
# val = 14

# print(TwoSum(arr,val))
   
