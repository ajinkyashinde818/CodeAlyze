from collections import  deque
S = input()
Q = int(input())
rev = 1
q = deque(list(S))
for _ in range(Q):
    op = input().split(" ")
    if int(op[0]) == 1:
        rev *= -1
    else:
        f, ch = op[1:]
        if rev == 1:
            if f == "1":
                q.appendleft(ch)
            else:
                q.append(ch)
        else:
            if f == "1":
                q.append(ch)
            else:
                q.appendleft(ch)
S = "".join(q)
if rev == -1:
    S = S[::-1]
print(S)
