from collections import Counter
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

num = [0]*(n+1)
bc = [0]*(n+1)


for i in range(n):
    num[a[i]] += 1
    num[b[i]] += 1
    bc[b[i]] += 1

if max(num) > n:
    print("No")

else:
    nc = []
    for i in range(n):
        nc.append([num[i+1], i+1])
    nc.sort(reverse = True)

    usenum = []
    tot = 0
    q = []
    rem_num = []
    for i in range(n):
        x, y = nc[i]
        if tot >= n:
            rem_num.append((bc[y], y))
            continue
        tot += x
        usenum.append(y)
        q.extend([y]*bc[y])


    q.reverse()
    usenum = set(usenum)
    a_index = set()
    for i in range(n):
        if a[i] not in usenum:
            a_index.add(i)


    ans = [None]*(n)
    for ai in a_index:
        ans[ai] = q.pop()

    a_remain = set([i for i in range(n)]) - a_index
    a_remain = list(a_remain)
    a_remain.sort()
    from collections import deque
    a_remain = deque(a_remain)


    while q:
        now = q.pop()
        while True:
            ins = a_remain.popleft()
            if a[ins] == now:
                a_remain.append(ins)
                continue
            else:
                ans[ins] = now
                break

    q = []
    for x, y in rem_num:
        q.extend([y]*x)

    while q:
        now = q.pop()
        ins = a_remain.pop()
        ans[ins] = now

    print("Yes")
    print(" ".join(map(str, ans)))
