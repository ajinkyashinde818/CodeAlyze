from collections import deque
s = input()
q = int(input())
former = deque()
latter = deque()

flg = False
for i in range(q):
    p = list(map(str, input().split()))
    if p[0] == "1":
        flg = True if flg == False else False
        continue
    else:
        if (p[1] == "1" and not flg) or (p[1] == "2" and flg):
            former.appendleft(p[2])
        else:
            latter.append(p[2])

ans = list(former) + list(s) + list(latter)
ans = "".join(ans)
print(ans if not flg else ans[::-1])
