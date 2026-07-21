from collections import deque

S = input()
Q = int(input())
head = 1
d = deque([S])

for _ in range(Q):
    q = input().split()
    if q[0]=='1':
        head = head*-1
    else:
        if q[1]=='1':
            h = head*1
        else:
            h = head*-1
        
        if h==1:
            d.appendleft(q[2])
        else:
            d.append(q[2])
ans = "".join(list(d))
if head == -1:
    ans = ans[::-1]

print(ans)
