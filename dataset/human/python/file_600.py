def MAP(): return list(map(int,input().split()))
def INT(): return int(input())
def FLOAT(): return float(input())
MOD = 10**9+7


n = INT()
a = MAP()

flag = False
cnt=0
for i in a:
    if i==0:
        flag = True
        break
    if i<0:
        cnt+=1
if cnt%2==0:
    flag = True

if flag:
    l = [abs(i) for i in a]
    print(sum(l))
else:
    l = [abs(i) for i in a]
    print(sum(l)-(2*min(l)))
