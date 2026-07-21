from _collections import deque

s = deque(input())
q = int(input())
reverse_flg = False

for i in range(q):
    query = list(input().split())
    if query[0] == '1':
        reverse_flg = not reverse_flg
    else:
        if query[1] == '1':
            if reverse_flg:
                s.append(query[2])
            else:
                s.appendleft(query[2])
        else:
            if reverse_flg:
                s.appendleft(query[2])
            else:
                s.append(query[2])
if reverse_flg:
    s.reverse()
print("".join(s))
