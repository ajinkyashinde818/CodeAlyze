from collections import deque

s = input()
c = int(input())

que = deque(s)

flipped = False
for i in range(c):
    query = input()
    
    if query[0] == '1':
        flipped = not flipped
    
    else:
        t, f, c = query.split()
        if (f == '1') ^ flipped:
            que.appendleft(c)
        
        else:
            que.append(c)



ans = ''.join(que)

if flipped:
    ans = ans[::-1]

print(ans)
