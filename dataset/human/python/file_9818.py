import sys
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
read = sys.stdin.buffer.read
sys.setrecursionlimit(10 ** 7)
INF = float('inf')

N, K = map(int, input().split())
A = list(map(int, input().split()))

if K <= N:
    pos = 0
    for _ in range(K):
        pos = A[pos] - 1
    print(pos+1)
    quit()

reached = [-1] * N
pos = 0
step = 0
while True:
    if reached[pos] != -1:
        loop_start = reached[pos]
        loop_end = step
        break
    reached[pos] = step
    pos = A[pos] - 1
    step += 1

K -= step
K = K % (loop_end - loop_start)

# print("loop_start: {}".format(loop_start))
# print("loop_end: {}".format(loop_end))
# print("K: {}".format(K))
# print("pos: {}".format(pos))
for _ in range(K):
    pos = A[pos] - 1

print(pos+1)
