from sys import stdin
il = lambda func=int: list(map(func, stdin.readline().rstrip().split()))
ils = lambda n, s="int(input())": [eval(s) for _ in range(n)]

n, m = il()
a = ils(n, "input()")
b = ils(m, "input()")
for i in range(n-m+1):
    for j in range(n-m+1):
        flag = 1
        for k in range(m):
            for l in range(m):
                if a[i+k][j+l] != b[k][l]:
                    flag = 0
        if flag:
            print("Yes")
            exit()
print("No")
