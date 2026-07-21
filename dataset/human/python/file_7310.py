from collections import deque
S = input()
Q = int(input())
t = []
f = []
c = []
for i in range(Q):
    in_ = list(input().split())
    if in_[0] == "1":
        t.append(1)
        f.append(0)
        c.append(0)
    else:
        t.append(2)
        f.append(int(in_[1]))
        c.append(in_[2])
acc = [0 for _ in range(Q)]
if t[-1] == 1:  acc[-1] = 1
for i in reversed(range(Q - 1)):
    if t[i] == 1:
        acc[i] = acc[i + 1] + 1
    else:
        acc[i] = acc[i + 1]
        
if acc[0] % 2 == 0:
    ans = deque(S)
else:
    ans = deque(S[::-1])
    
for i in range(Q):
    if t[i] == 2:
        if (f[i] + acc[i]) % 2 == 1:
            ans.appendleft(c[i])
        else:
            ans.append(c[i])
print("".join(ans))
