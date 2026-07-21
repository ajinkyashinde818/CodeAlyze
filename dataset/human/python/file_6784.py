from collections import deque

s=input()
query=int(input())

li_q = []
for _ in range(query):
    li_q.append(input().split())

rev = False
q_str = deque([s])
for q in li_q:
    if q[0] == '1':
        rev = not rev
    else:
        if q[1] == '1':
            if rev:
                q_str.append(q[2])
            else:
                q_str.appendleft(q[2])
        else:
            if rev:
                q_str.appendleft(q[2])
            else:
                q_str.append(q[2])

li_str = list(q_str)
ans = ''.join(li_str)
if rev:
    ans = ans[::-1]
    
print(ans)
