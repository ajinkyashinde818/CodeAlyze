def main():
    N, K = map(int,input().split())
    A = list(map(int,input().split()))
    A = [0] + A

    seen = {}
    find_cnt = {}
    cnt = 0
    dst = 1
    while K:
        if dst in seen:
            cycle = cnt - seen[dst]
            K %= cycle
            print(find_cnt[seen[dst]+K])
            return

        else:
            seen[dst] = cnt
            find_cnt[cnt] = dst

        dst = A[dst]
        cnt += 1
        K -= 1

    print(dst)


if __name__ == "__main__":
    main()
