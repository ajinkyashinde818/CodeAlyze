import sys
input=sys.stdin.readline

def main():
    N,C = map(int, input().split())
    X = []
    for _ in range(N):
        X.append(list(map(int, input().split())))
    
    cw = [0] # 時計回りに数えて i 番目までを食べた時に摂取できるカロリー
    ccw = [0] # 反時計回り
    for i in range(N):
        cw.append(cw[i] + X[i][1])
        ccw.append(ccw[i] + X[N-1-i][1])
    for i in range(N):
        cw[i+1] -= X[i][0]
        ccw[i+1] -= C - X[N-1-i][0]

    ma = 0
    ga = []
    for i in range(0, N+1):
        ma = max(ma, cw[i])
        ga.append(ma)
    ma = 0
    gb = []
    for i in range(0, N+1):
        ma = max(ma, ccw[i])
        gb.append(ma)

    ans = 0
    for bi in range(N+1):
        tmp = ccw[bi] + ga[N-bi]
        if bi > 0:
            tmp -= C - X[N-bi][0]
        ans = max(ans, tmp)

    for ai in range(N+1):
        tmp = cw[ai] + gb[N-ai]
        if ai > 0:
            tmp -= X[ai-1][0]
        ans = max(ans, tmp)

    print(ans)

if __name__ == '__main__':
    main()
