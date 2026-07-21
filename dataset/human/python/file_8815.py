def resolve():
    K, N = map(int, input().split()) 
    A_list = list(map(int, input().split()))

    max_interval = 0
    for i in range(N-1):
        tmp_interval = A_list[i + 1] - A_list[i]
        if max_interval < tmp_interval:
            max_interval = tmp_interval

    first_interval = A_list[0] + (K - A_list[N-1])

    if max_interval < first_interval:
        max_interval = first_interval

    ans = K - max_interval

    print(ans)

if __name__ == "__main__":
    resolve()
