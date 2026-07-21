from sys import stdin
n,k = [int(x) for x in stdin.readline().rstrip().split()]
a = [int(x) for x in stdin.readline().rstrip().split()]
b = [-1]*n
b[0] = 0
tf = True
t = 1
g = 0
m = 0
while k > 0:
    k -= 1
    if b[a[g]-1] == -1:
        b[a[g]-1] = t
    else:
        m = b[a[g]-1]
        g = a[g]-1
        break
    t += 1
    g = a[g]-1
mo = t-m
k = k % mo
while k > 0:
    g = a[g]-1
    k -= 1
print(g+1)
