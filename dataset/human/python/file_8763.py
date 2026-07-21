def solve():
    K, N = map(int, input().split())
    As = list(map(int, input().split()))

    dis = 0
    point = 0
    for i in range(1, N):
        tmp = As[i]-As[i-1]
        if tmp > dis:
            dis = tmp
            point = i

    if As[N-1]-As[0] < K-As[point]+As[point-1]:
        print(As[N-1]-As[0])
    else:
        print(K-As[point]+As[point-1])


if __name__ == "__main__":
    solve()
