import sys
input = sys.stdin.readline

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    now = 1
    l = []
    pre = [-1] * N
    turn = 0
    while True:
        if pre[now-1] != -1:
            break
        pre[now-1] = turn
        l.append(now)
        now = A[now-1]
        turn += 1

    if K < len(l):
        print(l[K])
    else:
        d = turn - pre[A[l[-1]-1]-1]
        f = len(l) - d
        t = (K - f) % d
        print(l[f+t])

if __name__ == "__main__":
    main()
