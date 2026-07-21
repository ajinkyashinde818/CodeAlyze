import sys
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)

K, N = map(int, readline().split())
A = list(map(int, readline().split()))

A.sort()
max_distance = A[0] + K-A[-1]

old = None
for a in A:
    if not old:
        old = a
        continue
    distance = a - old
    if distance > max_distance:
        max_distance = distance
    old = a

answer = K - max_distance
print(answer)
