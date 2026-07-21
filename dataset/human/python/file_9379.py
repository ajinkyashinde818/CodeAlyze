import sys

sys.setrecursionlimit(10**7)

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    visited = [False] * N
    cnt = [0] * N
    visited[0] = True
    B = [0]
    def dfs(s):
        tmp = A[s] - 1
        

        if visited[tmp]:
            B[0] = cnt[tmp]
            for i in range(N):
                if i == tmp:
                    continue
                cnt[i] -= cnt[tmp]
            cnt[tmp] = 0
            return
        
        cnt[tmp] = cnt[s] + 1
        visited[tmp] = True
        if cnt[tmp] == K:
            print(tmp + 1)
            exit()
        dfs(tmp)
    dfs(0)
    K -= B[0]
    t = K % (max(cnt)+1)
    for i in range(N):
        if cnt[i] == t:
            print(i+1)
            exit()
        
if __name__ == "__main__":
    main()
