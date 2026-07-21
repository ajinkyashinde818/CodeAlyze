import sys
import bisect
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
n,m = map(int,readline().split())
lst1 = []
for i in range(n):
    lst1.append(readline().rstrip().decode('utf-8'))

lst2 = []
for i in range(m):
    lst2.append(readline().rstrip().decode('utf-8'))

for i in range(n-m+1):
    for j in range(n-m+1):
        flag = 1
        for k in range(m):
            if lst1[i+k][j:j+m] != lst2[k]:
                flag = 0
        
        if flag:
            print("Yes")
            exit()
print("No")
