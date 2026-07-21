from collections import deque
def inputs(): return [int(x) for x in input().split()]
s = deque(input())
q = int(input())
flag = 1
for i in range(q):
    q1 = input()
    if len(q1)==1:
      flag *=-1 
    else:
        l,f,c = q1.split()
        if flag ==1:
            if int(f)==1:
                s.appendleft(c)
            else:
                s.append(c)
        elif flag==-1:
            if int(f)==1:
                s.append(c)
            else:
                s.appendleft(c)
if flag==1:
    print("".join(list(s)))
else:
    s = list(s)
    s = s[::-1]
    print("".join(list(s)))
