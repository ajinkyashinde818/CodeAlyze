INF = float("inf")
nl = lambda: list(map(int, input().split()))
sl = lambda: input().split()
n = lambda: int(input())
s = lambda: input()

D, G = nl()
problems = []
for i in range(D):
    p, c = nl()
    problems.append([p, c])

min_count = INF
import itertools
for p in itertools.product([False, True], repeat=D):
    point = 0
    count = 0
    max_false = -1
    for i in range(D):
        if not p[i]:
            max_false = i
        else:
            point += 100*(i+1)*problems[i][0] + problems[i][1]
            count += problems[i][0]
    if max_false == -1:
        if count < min_count:
            min_count = count
        continue
    if point + 100*(max_false+1)*(problems[max_false][0]-1) < G:
        continue
    left = max(G - point, 0)
    if left > 0:
        count += left // (100*(max_false+1))
        if left % (100*(max_false+1)) > 0:
            count += 1
    if count < min_count:
        min_count = count
print(min_count)
