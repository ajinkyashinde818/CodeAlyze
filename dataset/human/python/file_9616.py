n,k = map(int, input().split())
l = list(map(int, input().split()))

keys = range(1,n+1)
values = [-1]*n
dic = dict(zip(keys,values))
dic[1] = 0
t = 1
i = 1

def inverse_lookup(d, x):
    for k,v in d.items():
        if x == v:
            return k

while i <= k:
    t = l[t-1]
    if dic[t] != -1:
        m  = dic[t]
        d = i-m
        r = (k-i+1)%d
        if r == 0:
            r = d
        ans = inverse_lookup(dic, (m+r-1))
        print(ans)
        break
    dic[t] = i
    i += 1
if i == k+1:
    print(t)
