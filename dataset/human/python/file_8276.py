import numpy as np
n=int(input())
a=list(map(int,input().split()))
if sum(a)%((n*(n+1))//2):
    print("NO")
else:
    d=sum(a)//((n*(n+1))//2)
    c=[a[(i+1)%n]-a[i]for i in range(n)]
    for i in c:
        if i-d>0 or (i-d)%n:
            print("NO")
            break
    else:
        print("YES")
