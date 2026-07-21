from collections import deque

s = input()
q = int(input())
r = 1
top = deque()
top.append(s)
for _ in range(q):
    inp = input()
    if inp[0] == "1":
        r *= -1
    else:
        _, f, c = inp.split()
        if f == "1" and r == -1 or f == "2" and r == 1:
            top.append(c)
        else:
            top.appendleft(c)
ans = "".join(top)
print(ans if r == 1 else ans[::-1])
