from collections import deque

s = deque(input())
q = int(input())

query = []
rev=1

for i in range(q):
    query.append(input().split())

for i in range(q):
    if query[i][0]=="1":
        rev*=-1
    else:
        if rev==1:
            if query[i][1]=="1":
                s.appendleft(query[i][2])
            else:
                s.append(query[i][2])
        else:
            if query[i][1]=="2":
                s.appendleft(query[i][2])
            else:
                s.append(query[i][2])

result="".join(list(s))
if rev==-1:
    result = result[::-1]
print(result)
