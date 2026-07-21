def main():
    N, K = list(map(int, input().split()))
    A = list(map(int, input().split()))
    warp_idx = [-1] * (len(A) + 1)
    ans_list = []

    c = 1
    i = 0
    while warp_idx[c] == -1:
        warp_idx[c] = i
        ans_list.append(c)
        c = A[c - 1]
        i += 1
    start = warp_idx[c]
    loop = i - start
    if K <= start:
        print(ans_list[K])
    else:
        step = K - start
        step %= loop
        print(ans_list[start+step])


if __name__ == '__main__':
    main()
