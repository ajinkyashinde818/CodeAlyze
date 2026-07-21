import math

n = int(input())
list = {}
flag = True
while flag:
    flag = False
    for i in range(2,int(math.sqrt(n)+2)):
        if n%i==0:
            if i in list:
                list[i] = list[i]+1
            else:
                list[i] = 1
            n /= i
            flag = True
            break
if n>1:
    if n in list:
        list[n] = list[n]+1
    else:
        list[n] = 1
ans = 0
for i in list.keys():
    m = list[i]
    for j in range(1,m+1):
        if not j>m:
            ans += 1
            m -= j
        else:
            break
print(ans)
