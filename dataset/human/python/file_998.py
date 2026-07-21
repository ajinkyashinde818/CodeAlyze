import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

MOD = 10**9 + 7

N = int(input())
S = input().rstrip()

is_left = [(i%2 == 0) ^ (x == 'W') for i,x in enumerate(S)]

answer = 1
left = 0
for bl in is_left:
    if bl:
        left += 1
    else:
        answer *= left
        left -= 1
        answer %= MOD
if left != 0:
    answer = 0

for i in range(1,N+1):
    answer *= i
    answer %= MOD

print(answer)
