import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 7)

S = input().rstrip()

answer = 0
while S:
    if len(S) < 2:
        break
    L,R = S[0],S[-1]
    if L == R:
        S = S[1:-1]
        continue
    if L == 'x':
        answer += 1
        S = S[1:]
        continue
    if R == 'x':
        answer += 1
        S = S[:-1]
        continue
    answer = -1
    break

print(answer)
