N,K = map(int,input().split())
A = list(map(int,input().split()))

town = [0 for i in range(N+1)]

def next(A,now):
    return(A[now-1])

now = 1
i = 0
while True:
    if town[now] != 0:
        roop_start = town[now]
        roop_end = i
        break
    town[now] = i+1
    now = next(A,now)
    i += 1

roop = roop_end - roop_start + 1
teleport = min(roop_start + (K - roop_start)%roop,K)

now = 1
for i in range(teleport):
    now = next(A,now)

print(now)
