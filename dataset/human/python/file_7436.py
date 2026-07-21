from collections import deque
S = deque(input())
Q = int(input())
Query = [[] for _ in range(Q)]
for i in range(Q):
    Query[i] = list(map(str,input().split()))

fl = 0
for q in Query:
    if q[0]=='1':
        fl += 1
    else:#q[0]=='2'
        # 前に追加
        if (q[1]=='1'):
            # 反転あり
            if fl&1:
                S.append(q[2])
            # 反転なし
            else:
                S.appendleft(q[2])
        # 後に追加
        else:#q[1]=='2'
            # 反転あり
            if fl&1:
                S.appendleft(q[2])
            # 反転なし
            else:
                S.append(q[2])

T = ''.join(S)
if fl&1:
    T = T[::-1]
print(T)
