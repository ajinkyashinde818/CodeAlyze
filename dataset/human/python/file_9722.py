import sys
def MI(): return map(int,sys.stdin.readline().rstrip().split())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))  #空白あり


N,K = MI()
A = [0] + LI()

visited = [0]*(N+1)  # visited[i] = 町iに何回のテレポートで到着するか
times = [0]*(N+1)  # times[i] = i回目のテレポートでどの町に到着するか
i = 1
a = 0
visited[1] = 0
times[0] = 1
while True:
    i = A[i]
    a += 1
    times[a] = i
    if visited[i] != 0:
        b,c = visited[i],a  # 循環開始、終了
        break
    else:
        visited[i] = a

print(times[K] if K <= a else times[a+(K-a)%(b-a)])
