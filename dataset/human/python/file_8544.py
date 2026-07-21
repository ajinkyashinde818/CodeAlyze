from sys import stdin
import math
import fractions

n, k = [int(x) for x in stdin.readline().rstrip().split()]
a = [int(x) for x in stdin.readline().rstrip().split()]

w = 0
for i in range(k):
    if i != k - 1:
        temp = a[i+1] - a[i]
    else:
        temp = a[0] + n - a[i]
    if w < temp:
        w = temp
        
print(n - w)
