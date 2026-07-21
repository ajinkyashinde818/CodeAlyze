def main():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    cnt = [-1] * n
    cnt[0] = 0
    ary = []
    now = 0
    for i in range(n):
        a[i] -= 1

    ary.append(now)
    if k <= n:
        for i in range(1,k+1):
            now = a[now]
            if i == k:
                print(now+1)
                return
    else:
        for i in range(1,k+1):
            now = a[now]
            if cnt[now] != -1:
                break
            else:
                cnt[now] = i
                ary.append(now)
        loop_s = cnt[now]

        print(ary[cnt[now] +((k-cnt[now]) % (i - cnt[now]))] + 1)
        # print(cnt)
        # print(now)
        # print(ary)

if __name__=='__main__':
    main()
