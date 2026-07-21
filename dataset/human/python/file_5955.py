import itertools
import math
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))
 

ans = sum(b)
for i in range(n-1):
    ind = a[i] - 1
    ind_next = a[i+1] - 1
    if ind + 1 == ind_next:
        ans += c[ind]
print(ans)
"""
for i in range(len(a)):
    #print(type(a[i]))
    sum+=int(b[int(a[i])-1])

    if a[i]==int(a[i-1])+1:
        sum+=int(c[int(a[i])-1])
        
print(sum)

"""
