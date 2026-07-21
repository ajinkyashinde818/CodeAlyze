import numpy as np

N = int(input())
A = list(map(int, input().split()))
count = 0
point = 0 


for i in range(N):
    if A[i]==0:
        count = 1
        break
    elif A[i] < 0:
        point += 1

if count==1 or point%2==0:
    print(sum(np.abs(A)))

else:
    A1 = np.abs(A)
    A2 = min(A1)
    print(sum(A1)-2*A2)
