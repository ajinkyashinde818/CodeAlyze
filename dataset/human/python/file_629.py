import fractions

n = list(map(int, input().split()))
n = n[0]
a = list(map(int, input().split()))

count = 0
flag = 0
for i in range(n):
    if(a[i] == 0):
        flag = 1
        break
    if(a[i]<0):
        count = 1 - count

if(count == 0 and flag==0):
    flag = 1

abss = [abs(a[i]) for i in range(n)]

if(flag==1):
    print(sum(abss))
else:
    print(sum(abss) - 2*min(abss))
