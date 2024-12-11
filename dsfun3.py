# from collections import Counter

# def solve(n, arr):
#     arr.sort(reverse=True)
#     k = -1

#     for i in range(n):
#         if arr[i] <= i + 1:
#             k = i
#             break

#     if k == -1:
#         return k

#     mp = Counter(arr)

#     for i in range(k, n):
#         p = arr[i]
#         ct = 0
#         for key in mp:
#             if key % p == 0:
#                 ct += 1

#         if (ct%p == 0):
#             return ct

#     return -1

# if __name__ == "__main__":
#     n = int(input())
#     arr = list(map(int, input().split()))
#     print(solve(n, arr))

def solve(N, A):
    max_value = max(A) 
    divisible_count = [0] * (max_value + 1)
    
    for number in A:
        for i in range(1, int(number**0.5) + 1): 
            if number % i == 0:
                divisible_count[i] += 1
                if i != number // i:  
                    divisible_count[number // i] += 1
    
    special_number = -1
    for P in range(1, max_value + 1):
        if divisible_count[P] == P:
            special_number = max(special_number, P)
    
    return special_number

# Input
N = int(input()) 
A = list(map(int, input().split()))  

print(solve(N, A))
