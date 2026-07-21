from collections import deque
S = input()
L = deque()
L.append(S)
Q = int(input())
is_lookforward = True
for i in range(Q):
    query = input()
    if query[0] == '1':
        is_lookforward = not is_lookforward
    else:
        F = int(query[2])
        C = query[4]
        if (F == 1 and is_lookforward) or (F == 2 and not is_lookforward):
            L.appendleft(C)

        else:
            L.append(C)
ans = ''.join(L)
print(ans if is_lookforward else ans[::-1])
