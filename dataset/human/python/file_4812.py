def inpl(): return list(map(int, input().split()))

S = list(input())
T = list(input())
S.sort()
T.sort(reverse=True)

for i in range(min(len(S), len(T))):
    if S[i] < T[i]:
        print("Yes")
        exit()
    elif S[i] == T[i]:
        continue
    else:
        print("No")
        exit()
if len(S) >= len(T):
    print("No")
else:
    print("Yes")
