k, n = (int(x) for x in input().split())
arr = [int(x) for x in input().split()]

def dist(x, y):
    v = abs(x -y)
    return min(v, k-v)

arr.sort()

if n == 2:
    sol = dist(*arr)
else:
    sol = k - max(dist(arr[i-1], arr[i]) for i in range(n))

print(sol)
