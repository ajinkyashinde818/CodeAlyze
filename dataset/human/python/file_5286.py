from sys import stdin

n,m = [int(x) for x in stdin.readline().rstrip().split()]
li = [list(map(int,stdin.readline().rstrip().split())) for _ in range(m)]

lin = [0]*n

for i in li:
    if i[0] == 1:
        lin[i[1]-1] += 1
    if i[1] == n:
        lin[i[0]-1] += 1

for i in lin:
    if i == 2:
        print("POSSIBLE")
        exit()

print("IMPOSSIBLE")
