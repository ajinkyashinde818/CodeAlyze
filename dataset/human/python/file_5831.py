import numpy as np
n=int(input())
a=np.array([int(x) for x in input().split()])
b=np.array([int(x) for x in input().split()])
c=np.array([int(x) for x in input().split()])

tf = np.array([a[i+1] - a[i] == 1 for i in range(n-1)])

print(sum(b) + sum([c[j-1] for j in a[tf]]))
