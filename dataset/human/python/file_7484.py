from collections import deque

s = input()
q = int(input())
queries = [input() for i in range(q)]

ans = deque(s)
flag_reverse = False

for i in range(q):
    query = queries[i].split()
    if query[0] == "1":
        flag_reverse = not flag_reverse
    else:
        if query[1] == "1" and not flag_reverse or query[1] == "2" and flag_reverse:
            ans.appendleft(query[2])
        else:
            ans.append(query[2])

if flag_reverse:
    ans.reverse()

print("".join(ans))
