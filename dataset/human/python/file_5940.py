import math
N = input()
As =  list(map(int,input().split(" ")))
Bs =  list(map(int,input().split(" ")))
Cs =  list(map(int,input().split(" ")))

ans = 0
for i,a in enumerate(As):

    ans += Bs[a-1]

    if i != 0:
        if a - 1 == As[i-1]:
            ans +=Cs[a - 2]



print(ans)
