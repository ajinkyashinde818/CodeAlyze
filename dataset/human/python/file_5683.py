from collections import deque
S = deque(input())

ans = 0
while len(S):
    if S[0] == S[-1]:
        if len(S) > 1:
            S.popleft()
            S.pop()
        else:
            S.pop()
    else:
        if S[0] != "x" and S[-1] != "x":
            print(-1)
            exit()
        elif S[0] != "x":
            S.pop()
            ans += 1
        elif S[-1] != "x":
            S.popleft()
            ans += 1
print(ans)
