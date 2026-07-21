def sa(_a,_b):
    a = max(_a,_b)
    b = min(_a,_b)
    return a-b

n = int(input())
l = list(map(int,input().split()))
m = sum(l)
a = l[0]
b = m - a
ans = sa(a,b)
for i in range(1,len(l)-1):
    a += l[i]
    b -= l[i]
    ans = min(ans,sa(a,b))
print(ans)
