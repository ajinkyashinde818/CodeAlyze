from collections import deque
S = str(input())
Q = int(input())
Qy = list([input().split() for _ in range(Q)])
rev = False #反転チェック
ans = deque([S])
for t in Qy:
    if t[0] == '1':
        rev = not rev
    else:
        if (t[1]=='1' and rev == False) or (t[1]=='2' and rev == True):
            ans.appendleft(t[2])
        else:
            ans.append(t[2])
if rev == False:
    print(''.join(ans))
else:
    print(''.join(ans)[::-1])
