from collections import deque

s = input()
q = int(input())
queries = [input().split() for _ in range(q)]

judge = True
S = deque()
for string in s:
    S.append(string)

for query in queries:
    if query[0] == '1':
        judge = not judge
    else:
        if judge:
            if query[1] == '1':
                S.appendleft(query[2])
            else:
                S.append(query[2])
        else:
            if query[1] == '1':
                S.append(query[2])
            else:
                S.appendleft(query[2])
ans = ''.join(S)
if not judge:
    print(ans[::-1])
else:
    print(ans)
