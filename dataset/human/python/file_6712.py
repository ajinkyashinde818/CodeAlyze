from collections import deque
s = input().split()
sd = deque()
for i in s:
    sd.append(i)
N = int(input())
S = []
order = 1
for _ in range(N):
    res = input().split()
    if res[0] == "1":
        order = order * - 1
    elif res[1] == "1":
        if order == 1:
            sd.appendleft(res[2])
        else:
            sd.append(res[2])
    else:
        if order == 1:
            sd.append(res[2])
        else:
            sd.appendleft(res[2])

sd_str="".join(list(sd))
if order == -1:
    print(sd_str[::-1])
else:
    print(sd_str)
