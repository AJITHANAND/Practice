def solve(arr,n)->int:
    curr_change = 0
    i=0
    while i<=n-3:
        if arr[i:i+3] == '010':
            curr_change += 1
            i+=3
        else:
            i += 1
    return curr_change
def main():
    n = int(input())
    arr = input()
    print(solve(arr,n))


if __name__ == "__main__":
    main()