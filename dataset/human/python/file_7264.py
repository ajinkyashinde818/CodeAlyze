from collections import deque
S = input()
Q = int(input())

state = 1 # 反転していたら-1
Stock = deque([S])
for i in range(Q):
    q = input()
    if q == '1':
        state *= -1
    else:
        Y, f, c = q.split()
        if (state == 1 and f == '1') or (state == -1 and f == '2'):
            Stock.appendleft(c)
        elif (state == 1 and f == '2') or (state == -1 and f == '1'):
            Stock.append(c)
S = ''.join(Stock)
if state == -1:
    S = S[::-1]
print(S)
