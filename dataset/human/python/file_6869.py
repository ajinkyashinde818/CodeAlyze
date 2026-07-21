import collections

d = collections.deque()
for i in input():
    d.append(i)
q = int(input())
is_head = True

for _ in range(q):
    tmp = input().split(" ")
    if (len(tmp) == 1):
        is_head = not is_head
    else:
        t, f, c = tmp
        if (f == '1'):
            if (is_head):
                d.appendleft(c)
            else:
                d.append(c)
        else:
            if (is_head):
                d.append(c)
            else:
                d.appendleft(c)

ans = ""
if is_head:
    while len(d) > 0:
        ans += d.popleft()
else:
    while len(d) > 0:
        ans += d.pop()
print(ans)
