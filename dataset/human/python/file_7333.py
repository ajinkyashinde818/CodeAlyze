from collections import deque
S = input()
Q = int(input())

T = [None] * Q
F = [None] * Q
C = [None] * Q
for i in range(Q):
    query = input().split()
    T[i] = int(query[0])
    if len(query) == 3:
        F[i] = int(query[1])
        C[i] = query[2]

ans = deque([S])
cnt1 = 0  # T[i]の偶奇
for i in range(Q):
    if T[i] == 1:
        cnt1 = (cnt1 + 1) % 2
    elif F[i] == 1:  # 先頭にCi追加
        if cnt1 == 0:  # そのまま
            ans.appendleft(C[i])
        else:   # 逆順にして末尾に追加
            ans.append(C[i][::-1])
    else:  # 末尾にCi追加
        if cnt1 == 0: # そのまま
            ans.append(C[i])
        else:
            ans.appendleft(C[i][::-1])

ans = ''.join(ans)

if cnt1 == 1:
    ans = ans[::-1]

print(ans)
