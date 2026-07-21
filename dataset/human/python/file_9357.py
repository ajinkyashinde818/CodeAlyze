def main():
    import sys
    input = sys.stdin.readline
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    cnt = 0
    used = [-1] * N
    used[0] = 0
    cur = 0
    loop_cnt = 0
    start = 0
    for i in range(1, N+1):
        cur = A[cur] - 1
        if i == K:
            print(cur+1)
            sys.exit() 
        if used[cur] == -1:
            used[cur] = i
            continue
        else:
            loop_cnt = i
            start = cur
            break
    K -= loop_cnt
    loop_cnt -= used[start]
    x = K % loop_cnt
    for i in range(N):
        if used[i]-used[start] == x:
            print(i+1)

if __name__ == '__main__':
    main()
