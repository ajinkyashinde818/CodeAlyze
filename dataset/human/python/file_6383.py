def two_int():
    N, K = map(int, input().split())
    return N,K

def one_int():
    return int(input())

def one_str():
    return input()

def many_int():
    return list(map(int, input().split()))

N=one_int()

if N%2==0:
    sums =0
    for i in range(1,26):
        sums += (N//2)//(5**i)
    print(int(sums))
else:
    print(0)
