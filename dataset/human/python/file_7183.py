from collections import deque
S = deque(list(input()))
Q = int(input())
re = 0
for i in range(Q):
    X = input().split()
    if X[0] == "1":
        re += 1
    else:
        if (int(X[1]) + re)%2 == 1:
            S.appendleft(X[2])
        else:
            S.append(X[2])
while S:
    if re % 2:
        print(S.pop(),end = "")
    else:
        print(S.popleft(),end = "")
print()
