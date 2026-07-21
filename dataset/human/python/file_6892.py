from collections import deque
S = list(input())
Q = int(input())
ans = deque(S)
a = 1
for i in range(Q):
    q = input()
    if q == '1':
        a *= -1
    else:
        d, f, c = q.split()
        if f == '1':
            if a == 1:
                ans.appendleft(c)
            else:
                ans.append(c)
        else:
            if a == 1:
                ans.append(c)
            else:
                ans.appendleft(c)

ans = ''.join(list(ans))
if a == -1:
    ans = ans[::-1] 

print(ans)
