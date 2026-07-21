import sys

n,m = map(int,input().split())
a = [[] for i in range(n)]
b = [[] for j in range(m)]
for i in range(n):
    a[i] = input()
for i in range(m):
    b[i] = input()
    
mal = n-m+1
for i in range(mal):
    for j in range(mal):
        fl = 1
        for k in range(m):
            for l in range(m):
                if a[i+k][j+l] != b[k][l]:
                    fl = 0
                    
        if fl == 1:
            print("Yes")
            sys.exit()
            
print("No")
