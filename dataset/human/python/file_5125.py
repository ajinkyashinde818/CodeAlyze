import sys
n,m = map(int,input().split())

a = [list(map(int,input().split()))for i in range(m)]

a.sort()

k = [0 for i in range(n)]

for i in range(m):
    if a[i][0] != 1:
        break
    else:
        k[a[i][1]-1] = 1

for i in range(m):
    if k[a[i][0]-1] == 1:
        if a[i][1] == n:
            print("POSSIBLE")
            sys.exit()
print("IMPOSSIBLE")
