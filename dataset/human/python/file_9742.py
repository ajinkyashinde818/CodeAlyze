def change(a):
    return int(a) - 1


n, k = map(int, input().split())

ls = list(map(change, input().split()))
visited = [False] * n
visited[0] = True
i = 0
while True:
    if not visited[ls[i]]:
        visited[ls[i]] = True
        i = ls[i]
    else:
        end = ls[i]
        break
loop = 0
i = end
while True:
    if ls[i] == end:
        loop += 1
        break
    else:
        i = ls[i]
        loop += 1

i = 0
till_loop = 0
while True:
    if ls[i] == end:
        till_loop += 1
        break
    else:
        i = ls[i]
        till_loop += 1
if till_loop + loop <= k:
    k -= till_loop
    k %= loop
    i = end
    while k > 0:
        i = ls[i]
        k -= 1
    print(i+1)
else:
    i = 0
    while k > 0:
        i = ls[i]
        k -= 1
    print(i+1)
