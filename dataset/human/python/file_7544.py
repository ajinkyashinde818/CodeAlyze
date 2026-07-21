from collections import deque

S = input()
S = deque(S)
Q = int(input())
Query1 = 0
flag = False
for i in range(Q):
    Queryi = input().split()
    if Queryi[0] == '1':
        Query1 += 1
        flag = not flag
    else:
        if (Queryi[1] == '1') ^ flag:
            S.appendleft(Queryi[2])
        else:
            S.append(Queryi[2])

if Query1 % 2 != 0:
    S.reverse()

ans = ''.join(S)
print(ans)
