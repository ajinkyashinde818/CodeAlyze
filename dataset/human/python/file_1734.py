from sys import stdin

n,m = [int(x) for x in stdin.readline().rstrip().split()]

li = [["" for i in range(n)]for j in range(n)]
for i in range(n):
    s = stdin.readline().rstrip()
    for j in range(n):
        li[i][j] = s[j]

lin = [["" for i in range(m)]for j in range(m)]
for i in range(m):
    s = stdin.readline().rstrip()
    for j in range(m):
        lin[i][j] = s[j]

for i in range(n-m+1):
    for j in range(n-m+1):
        point = 0
        for k in range(m):
            for l in range(m):
                if lin[k][l] == li[k+i][l+j]:
                    point += 1
                    if point == m**2:
                        print("Yes")
                        exit()
                        
print("No")
