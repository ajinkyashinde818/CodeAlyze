import sys
n, k = map(int, input().split())
A = list(map(int, input().split()))
flags = [False] * n
steps = [0] * n
next_place = 1
step = 0
if k <= n:
    for i in range(k):
        next_place = A[next_place - 1]
    print(next_place)
    sys.exit(0)
for i in range(n):
    step += 1
    next_place = A[next_place - 1]
    if flags[next_place - 1]:
        ## 循環
        loop_start = steps[next_place - 1]
        loop_length = step - loop_start
        break
    else:
        flags[next_place - 1] = True
        steps[next_place - 1] = step
iteration = (k - loop_start) % loop_length
for i in range(iteration):
    next_place = A[next_place - 1]
print(next_place)
