from collections import deque
d = deque()
d.extend(list(input()))
q = int(input())
z = 0
F = ""
R = ""
for i in range(q):
    a = tuple(input().split())
    if a[0] == "1":
        z += 1
        z %= 2
    else:
        if (int(a[1]) + z) % 2 == 0:
            d.append(a[2])
        else:
            d.appendleft(a[2])

ans = "".join(d)
if z % 2 == 0:
    print(ans)
else:
    print(ans[::-1])
