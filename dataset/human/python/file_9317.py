import sys

N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
A = [0] + A
town = 1
visited = [0]*(N+1)

for i in range(1, K+1):
    town = A[town]
    if visited[town] == 0:
        visited[town] = i
    else:
        loop = i - visited[town]
        place = (K - visited[town]) % loop + visited[town]
        print(visited.index(place))
        sys.exit()
print(town)
