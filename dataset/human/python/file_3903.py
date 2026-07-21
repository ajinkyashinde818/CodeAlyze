import sys
import math
from collections import deque
from collections import defaultdict

def factorization(n):
    arr = {}
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr[i] = cnt

    if temp!=1:
        arr[temp] = 1

    if arr==[]:
        arr[n] = 1

    return arr

def main():
    n = int(sys.stdin.readline())
    base = factorization(n)
    ans = 0
    for x in list(base.keys()):
        i = 1
        while(base[x] >= i):
            base[x] -= i
            ans += 1
            i += 1
    print(ans)
    return 0

if __name__ == "__main__":
    main()
