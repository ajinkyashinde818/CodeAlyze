from collections import deque

s = input()
q = int(input())
query = [input() for _ in range(q)]

s = deque(s)

inv = 0
for q in query :
    if q[0] == '1':
        inv += 1
    else:
        _,f,c = q.split()
        if f == '1':
            if inv % 2 == 0:
                s.appendleft(c)
            else:
                s.append(c)
        else:
            if inv % 2 ==0:
                s.append(c)
            else:
                s.appendleft(c)
s = ''.join(s)
print(s if inv % 2 == 0 else s[::-1])
