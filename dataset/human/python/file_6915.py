from collections import deque
S = list(input())
Q = int(input())

d = deque()
d.extend(S)
cnt = 0
for i in range(1, Q+1):
    query = input()
    if len(query) == 1:
        cnt += 1
    else:
        n, F, C = query.split()
        if cnt % 2 == 0:  # 反転cntが偶数,F=1で末尾
            if F == '1':
                d.appendleft(C)
            else:
                d.append(C)
        else:  # 反転cntが偶数,F=1で先頭
            if F == '1':
                d.append(C)
            else:
                d.appendleft(C)

if cnt % 2 == 1:  # cnt奇数の場合、反転
    d.reverse()
else:
    pass

l = list(d)
S = ''.join(l)
print(S)
