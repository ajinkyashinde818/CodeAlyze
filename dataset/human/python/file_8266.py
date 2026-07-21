def check(N, A):
    S = N * (1+N) // 2
    total = sum(A)
    if total % S != 0:
        return False
    cnt = total//S
    tmp = cnt
    for i in range(N):
        diff = A[i] - A[(i+1) % N]
        if (diff + cnt) % N != 0 or (diff + cnt) < 0:
            return False
        tmp -= (diff + cnt) // N
    return tmp == 0


def main():
    N = int(input())
    A = list(map(int, input().split()))
    if check(N, A):
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()
