import sys
input = sys.stdin.buffer.readline

N = int(input())
A = list(map(int, input().split()))

cnt = 0
min_abs = 10 ** 15
for a in A:
    if a < 0:
        cnt += 1
    min_abs = min(min_abs, abs(a))
        
if cnt % 2 == 0:
    print(sum(map(abs, A)))
else:
    print(sum(map(abs, A)) - min_abs * 2)
