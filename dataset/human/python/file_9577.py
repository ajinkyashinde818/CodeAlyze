from sys import stdin
input = stdin.readline

N, K = map(int, input().split())
A = list(map(int, input().split()))

graph = []

time = [-1] * N

now = 0
nex = 0
time[0] = 0
loop = 0

while True:
    now = nex
    nex = A[now] - 1

    if time[nex] == -1:
        time[nex] = time[now] + 1
    else:
        loop = nex
        break

if K > max(time):
    K -= time[loop]
    K %= (max(time) - time[loop] + 1)
    tmp = time[loop]
    for i in range(N):
        time[i] -= tmp

for i in range(N):
    if time[i] == K:
        print(i + 1)

# print(time, K)
