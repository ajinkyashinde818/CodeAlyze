import sys


try:
    sys.stdin = open(sys.path[0] + '/input.txt', 'r')
    sys.stdout = open(sys.path[0] + '/output.txt', 'w')
except FileNotFoundError:
    pass


n, k = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr = [i - 1 for i in arr]

p = 0
route = []
seen = set()

while True:
    route.append(p)
    seen.add(p)

    p = arr[p]
    if p in seen:
        break

loop_start = route.index(p)
loop_len = len(route) - loop_start

if k <= loop_start:
    print(route[k] + 1)
else:
    rem = (k - loop_start) % loop_len
    print(route[loop_start + rem] + 1)
