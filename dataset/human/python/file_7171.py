from collections import deque
S = input()
Q = int(input())
R = deque(S)
rev = 0

for i in range(Q):
    T = input().split()
    if T[0] == '1':
        rev += 1
    else:
        if T[1] == '1':
            if rev % 2 == 0:
                R.appendleft(T[2])
            else:
                R.append(T[2])
        else:
            if rev % 2 == 0:
                R.append(T[2])
            else:
                R.appendleft(T[2])
ans = ''.join(R)
if rev % 2 ==0:
    print(ans)
else:
    print(ans[::-1])
