from collections import deque
S = input()
Q = int(input())
r = 0
s = deque(S)
for i in range(Q):
    q = input().split()
    if q[0]=='1':
        r += 1
    else:
        f = int(q[1])
        f += r
        f %= 2
        if f==0:
            s.append(q[2])
        else:
            s.appendleft(q[2])
ans = ''.join(s)
if r%2==1:
    ans = ans[::-1]
print(ans)
