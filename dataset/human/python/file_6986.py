from collections import deque
s = str(input())
q = int(input())
s = deque(s)
query = []
w = True
for i in range(q):
    query = list(map(str,input().split()))
    if(query[0] == "1"):
        w = not(w)
    else:
        mem = query[2]
        if(query[1] == "1"):
            if(w):
                s.appendleft(mem)
            else:
                s.append(mem)
        else:
            if(w):
                s.append(mem)
            else:
                s.appendleft(mem)
if(w):
    print("".join(s))
else:
    s.reverse()
    print("".join(s))
