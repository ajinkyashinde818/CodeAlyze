from collections import deque
s = deque([i for i in input()])
q = int(input())
cnt = 0
for _ in range(q):
    s_ = input()
    if len(s_) == 1: cnt += 1
    else:
        if (int(s_[2]) + cnt % 2) % 2 == 0: s.append(s_[4])
        else: s.appendleft(s_[4])
if cnt % 2 == 1: print("".join(list(s)[::-1]))
else: print("".join(s))
