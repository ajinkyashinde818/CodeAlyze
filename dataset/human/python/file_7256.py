from collections import deque
S = str(input())
Q = int(input())
query = [ input().split() for _ in range(Q) ]

tag = False
que = deque([S])

for i in range(Q):
    if query[i][0] == str(1):
        if tag == False:
            tag = True
        else:
            tag = False
    elif query[i][0] == str(2):
        if query[i][1] == str(1):
            if tag == False:
                que.appendleft(query[i][2])
            else:
                que.append(query[i][2])
        else:
            if tag == False:
                que.append(query[i][2])
            else:
                que.appendleft(query[i][2])
ans = "".join(que)
if tag == True:
    ans = ans[::-1]
print(ans)
