import sys

a=list(input())
b=list(input())
a.sort()
b.sort(reverse=True)
n=len(a)
m=len(b)

for i in range(min(n,m)):
    if a[i]>b[i]:
        print("No")
        sys.exit()
    elif a[i]<b[i]:
        print("Yes")
        sys.exit()
if n>=m:
    print("No")
else:
    print("Yes")
