from collections import deque


s = list(input())
q = int(input())
queries = [input().split() for _ in range(q)]
for i in range(q):
    queries[i][0] = int(queries[i][0])
    if queries[i][0] == 2:
        queries[i][1] = int(queries[i][1])

revised_queries = []
reverse_num = 0

for query in reversed(queries):
    q_type = query[0]
    if q_type == 1:
        reverse_num += 1
        continue
    f_b = query[1]
    c = query[2]
    if reverse_num % 2 == 1:
        f_b = 2 if f_b == 1 else 1
    revised_queries.append([f_b, c])

if reverse_num % 2 == 1:
    s = reversed(s)

s = deque(s)
for _ in range(len(revised_queries)):
    query = revised_queries.pop()
    f_b = query[0]
    c = query[1]
    if f_b == 1:
        s.appendleft(c)
    else:
        s.append(c)
print("".join(list(s)))
