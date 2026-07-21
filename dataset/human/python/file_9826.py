import sys
input = sys.stdin.readline

N, K = map(int, input().split())
A = list(map(lambda x: int(x)-1, input().split()))
cities = [0]
c = 0
used = [False] * N
used[0] = True
while not used[A[c]]:
    used[A[c]] = True
    cities.append(A[c])
    c = A[c]
x = cities.index(A[c])
if K < x:
    print(cities[K] + 1)
else:
    K -= x
    K %= len(cities) - x
    print(cities[x + K] + 1)
