from collections import deque
s = deque(list(input()))
q = int(input())
que = [list(input().split()) for _ in range(q)]
counter = 0
for i in que:
    if i[0] == "1":
        counter += 1
    else:
        if (counter+int(i[1]))%2==1:
            s.appendleft(i[-1])
        else:
            s.append(i[-1])
if counter%2==0:
    print("".join(list(s)))
else:
    print("".join(list(s)[::-1]))
