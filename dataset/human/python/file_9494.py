def main():
    N, K = list(map(int, input().split()))
    A = list(map(lambda x: int(x) - 1, input().split()))
    B = [-1] * N
    B[0] = K
    c = 0
    k = K
    while k:
        c = A[c]
        k -= 1
        if B[c] != -1:
            k %= (B[c] - k)
        B[c] = k
    return c + 1

print(main())
