from collections import deque
S = input()
Q = int(input())
ans = deque(S)
rev_flag = False
for i in range(Q):
    query = input()
    if query == "1":
        rev_flag = not rev_flag
    elif not rev_flag:
        if query[2] == "1":
            ans.appendleft(query[4])
        else:
            ans.append(query[4])
    else:
        if query[2] == "2":
            ans.appendleft(query[4])
        else:
            ans.append(query[4])

if rev_flag:
    ans.reverse()

print("".join(ans))
