from collections import deque

N, K = map(int, input().split())
A = list(map(int, input().split()))
stack = deque([])
passed = set()
town = 0
while town not in passed:
    passed.add(town)
    stack.append(town)
    town = A[town] - 1

if len(stack) > K:
    print(stack[K] + 1)
    import sys
    sys.exit()

tail = 0
while stack[0] != town:
    _ = stack.popleft()
    tail += 1

K -= tail
K += 1
tmp = K % len(stack)
if tmp == 0:
    tmp = len(stack)
print(stack[tmp - 1] + 1)
