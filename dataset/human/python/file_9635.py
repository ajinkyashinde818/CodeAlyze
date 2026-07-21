import collections

def getls():
    return [ipt for ipt in input().split()]
def getlsi():
    return [int(ipt) for ipt in input().split()]

[n,k] = getlsi()
a = getlsi()

dic = collections.defaultdict(int)

now = 1

cnt = 1
while dic[now] == 0:
    dic[now] = cnt
    now = a[now-1]
    cnt += 1
lp = cnt - dic[now]
if k <= dic[now]:
    next = 1
    for i in range(k):
        next = a[next-1]
    print(next)
else:
    next = 1
    tmp = (k+1 - dic[now]) % lp
    #print(tmp)
    for i in range(dic[now]+ tmp-1):
        #print(next)
        next = a[next-1]
    print(next)
#else:
