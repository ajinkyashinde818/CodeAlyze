from collections import deque

S=input()
Q=int(input())

t=deque(S)
flag_r=0
for _ in range(Q):
    Query=input().split()
    if int(Query[0])==1:
        flag_r=(flag_r+1)%2
    elif int(Query[1])==1+flag_r:
        t.appendleft(Query[2])
    else:
        t.append(Query[2])
result=''.join(t)
if flag_r:# reverseは最後にやる
    result=result[::-1]
print(result)
