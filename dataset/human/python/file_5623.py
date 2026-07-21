import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

S = input()[:-1]
N = len(S)
ans = 0
left = 0
right = N-1

while left <= right:
    if S[left] == S[right]:
        left += 1
        right -= 1
    elif S[left] == "x":
        left += 1
        ans += 1
    elif S[right] == "x":
        right -= 1
        ans += 1
    else:
        print(-1)
        break
else:
    print(ans)
