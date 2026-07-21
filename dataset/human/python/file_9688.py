import sys
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    N, K = map(int, readline().split())
    A = [0] + list(map(int, readline().split()))
    visit = [0]*(N+1)
    nx = 1
    count = 0
    while True:
        now = nx
        nx = A[now]
        count += 1
        if visit[nx] == 0:
            if count == K:
                print(nx)
                break
            else:
                visit[nx] = count
                continue
        else:
            move = (K - visit[nx]) % (count - visit[nx])
            city = visit.index(visit[nx] + move)
            print(city)
            break






if __name__ == '__main__':
    main()
