import sys
def input():
    return sys.stdin.readline().rstrip('\n')


def calc(N, K, A):
    n = 1
    k = 0
    d = {n: k}
    while True:
        k += 1
        n = A[n - 1]
        if k == K or n == A[n - 1]:
            return n
        if not n in d:
            d[n] = k
        else:
            x = (K - d[n]) % (k - d[n]) + 1
            for i in d:
                if d[i] == d[n] - 1 + x:
                    return i
            return -1

    

(N, K) = tuple([int(s) for s in input().split()])
A = [int(s) for s in input().split()]
print(calc(N, K, A))
