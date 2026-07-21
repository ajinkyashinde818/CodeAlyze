import sys
import random

def test(K, N, A):
    ans = []
    maxp = N-1
    minp = 0
    for i in range(len(A)):
        ans.append(A[maxp] - A[minp])
        A[i] += K
        maxp = (maxp + 1) % (N)
        minp = (minp + 1) % (N)
    print(min(ans))

if __name__ == "__main__":
    if "random" in sys.argv:
        K = int(random.random() * 20000)
        N = int(random.random() * 65536)
        A = sorted([int(random.random() * K) for _ in range(N)])
    else:
        K, N = [int(x) for x in input().split()]
        A = [int(x) for x in input().split()]
    test(K,N,A)
    pass
