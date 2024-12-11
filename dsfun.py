def main():
    n = int(input()) 

    a_values = list(map(int, input().split())) 
    b_values = list(map(int, input().split())) 

    p = list(zip(a_values, b_values))

    p.sort()

    lis = []
    for i in range(n):
        b_value = p[i][1]
        pos = binary_search(lis, b_value)
        if pos == len(lis):
            lis.append(b_value)
        else:
            lis[pos] = b_value

    print(len(lis))  

def binary_search(arr, x):
    lo, hi = 0, len(arr)
    while lo < hi:
        mid = (lo + hi) // 2
        if arr[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo

if __name__ == "__main__":
    main()
