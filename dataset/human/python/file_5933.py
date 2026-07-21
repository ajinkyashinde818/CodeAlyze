from sys import stdin

n = int(input())
a = [ int(x) for x in stdin.readline().rstrip().split()]
b = [ int(x) for x in stdin.readline().rstrip().split()]
c = [ int(x) for x in stdin.readline().rstrip().split()]
cnt = 0

for i in range(n):
    j = a[i]-1
    cnt += b[j]
    if i>0:
        if a[i]-1 == a[i-1]:
            if  j> a[i-1]-1:
                cnt+=c[a[i-1]-1]

print(cnt)
