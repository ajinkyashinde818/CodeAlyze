from sys import stdin


inp = stdin.readline

n, k = [int(x) for x in inp().strip().split()]

array = [int(x) for x in inp().strip().split()]

distance = [0]*(k * 2)

for i in range(k - 1):
    distance[i] = array[i+1] - array[i]

distance[k-1] = n-array[k-1] + array[0]

print(n-max(distance))
