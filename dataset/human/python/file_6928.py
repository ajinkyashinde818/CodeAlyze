from collections import deque
s = input()
q = int(input())
reverse_now = 0
first = deque([])
latter = ""
for i in range(q):
    k = list(input().split())
    if k[0] == "1":
        reverse_now = 1 - reverse_now
    else:
        f,c = k[1], k[2]
        if f == "1" and reverse_now == 0:
            first.appendleft(c)
        if f == "1" and reverse_now == 1:
            latter += c
        if f == "2" and reverse_now == 0:
            latter +=  c
        if f == "2" and reverse_now == 1:
            first.appendleft(c)
first = "".join(first)
if reverse_now == 1:
    ans = list(first + s + latter)
    ans.reverse()
    ans = "".join(ans)
else:
    ans = first + s + latter
print(ans)
