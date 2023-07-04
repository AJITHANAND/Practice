# https://www.hackerrank.com/challenges/luck-balance/problem

import bisect 

def main():
    n,k = map(int,input().split())
    imp = []
    non_imp = 0
    total= 0
    for _ in range(n):
        val,is_imp = map(int,input().split())
        if is_imp ==1:
            bisect.insort(imp,int(val))
            total += val
        else:
            non_imp +=val
    print(non_imp+total-2*sum(imp[:max(0,len(imp)-k)]))        


if __name__=="__main__":
    main()