import sys
import math
import bisect

def solve(A, B, C):
    n = len(A)
    ans = sum(B)
    for i in range(n):
        if i < n - 1 and A[i] + 1 == A[i+1]:
            ans += C[A[i]-1]
    return ans

def main():
    n = int(input())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    C = list(map(int, input().split()))
    print(solve(A, B, C))

if __name__ == "__main__":
    main()
