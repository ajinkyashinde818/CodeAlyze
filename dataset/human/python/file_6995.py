from collections import deque

s = deque(input())
Q = int(input())
    
t = True
    
for i in range(Q):
    query = input().split()
    if query[0] == '1':
        t = not t
    else:
        if(t and query[1] == '1') or (not t and query[1] == '2'):
            s.appendleft(query[2])
        else:
            s.append(query[2])
            
s = ''.join(s)
    
if not t:
    s = s[::-1]
        
print(s)
