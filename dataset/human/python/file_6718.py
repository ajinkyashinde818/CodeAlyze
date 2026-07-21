from collections import deque

revFlag = False

s = deque(input())
q = int(input())

for i in range(q):
    a,b,c, *_ = input().split() + [None, None]
    
    if(a == '1'):
        revFlag = not revFlag
        
    else:
        b = int(b)
        if(revFlag):
            b = (int(b)%2)+1
        
        if(b == 1):
            s.appendleft(c)
        else:
            s.append(c)
            
    #print(_,*s, sep="")

if(revFlag):
    s.reverse()
    
print(*s, sep='')
