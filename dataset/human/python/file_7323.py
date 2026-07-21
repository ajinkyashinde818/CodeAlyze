from collections import deque

S = deque(input())
Q = int(input())
reverse = 1


for i in range(Q):
    
    q = input()
    
    if (q == '1'):
        reverse *= -1
    else:
        integer, judge, cha = q.split()
        
        if (judge == '1'):
            if (reverse == 1):
                S.appendleft(cha)
            else:
                S.append(cha)
        
        elif (judge == '2'):
            if (reverse == 1):
                S.append(cha)
            else:
                S.appendleft(cha)

if (reverse == -1):
    S.reverse()

print(''.join(list(S)))
