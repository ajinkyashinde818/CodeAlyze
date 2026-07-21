import numpy as np
n, m = map(int,input().split())
A = []
B = []
for i in range(n):
    a = list(input())
    A.append(a)
for i in range(m):
    b = list(input())
    B.append(b)
A_arr = np.array(A)
B_arr = np.array(B)

for h in range(n-m+1):
    for w in range(n-m+1):
        if np.all(A_arr[h:h+m, w:w+m] == B_arr):
            print("Yes")
            exit()
print("No")
