import sys
input = sys.stdin.readline
n,k = map(int,input().split())
alist = list(map(lambda x:int(x) - 1,input().split()))
count = [0]*n
count[0] += 1
now = 0
order = [0]
for i in range(k):
    now = alist[now]
    count[now] += 1
    if count[now] == 2:
        start = order.index(now)
        loop = len(order[start:])
        syoki = len(order[:start])
        break
    order.append(now)
else:
    print(now+1)
    exit()
k -= syoki
k %= loop
print(order[k+syoki] + 1)
