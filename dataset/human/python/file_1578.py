import numpy as np
n,m = map(int,input().split())
a = np.array([list(input()) for i in range(n)])
b = np.array([list(input()) for i in range(m)])
ans = 'No'
for i in range(n-m+1):
    for j in range(n-m+1):
        if (a[j:j+m,i:i+m] == b).all():
            ans = 'Yes'
            break
print(ans)
