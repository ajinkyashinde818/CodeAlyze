import collections
n,k = map(int,input().split())
a = list(map(int,input().split()))
list = [1]
i = 0
num = a[0]
for i in range(3*n):
    list.append(num)
    num = a[num-1]

cnt = collections.Counter(list)
onevalue = [k for k,v in cnt.items() if v == 1]
lstart = len(onevalue)
lroop = len(set(list))-lstart

if k <= lstart:
    num = a[0]
    for i in range(k-1):
        num = a[num-1]
    print(num)
    exit()
elif lstart == 0:
    k = (k-lstart)%lroop
    num = 1
    for i in range(k):
        num = a[num-1]
    print(num)
    exit()
else:
    k = (k-lstart)%lroop
    num = a[0]
    if lstart > 0:
        for i in range(lstart-1):
            num = a[num-1]
    for i in range(k):
        num = a[num-1]
    print(num)
    exit()
