def main():
    N, K = map(int, input().split())
    A_i = list(map(lambda x: int(x)-1, input().split()))

    v = [False] * N
    c = 0

    while True:
        if K == 0:
            print(c+1)
            return
        if v[c]:
            break
        v[c] = True
        c = A_i[c]
        K -= 1

    x = c
    y = 0
    while True:
        if K == 0:
            print(c+1)
            return
        c = A_i[c]
        K -= 1
        y += 1
        if x == c:
            break

    K = K % y
    while True:
        if K == 0:
            print(c+1)
            return
        c = A_i[c]
        K -= 1


main()
