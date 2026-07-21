from collections import deque

s = deque(input())
q = int(input())

reverse_flag = -1 # -1なら反転しない

for i in range(q):
    query = list(input().split())
    if query[0] == '1':
        reverse_flag *= -1
    else:
        if query[1] == '1':
            if reverse_flag == -1:
                deque.appendleft(s, query[2])
            else:
                deque.append(s, query[2])
        else:
            if reverse_flag == -1:
                deque.append(s, query[2])
            else:
                deque.appendleft(s, query[2])
                
if reverse_flag == 1:
    s.reverse()
    
print(''.join(s))
