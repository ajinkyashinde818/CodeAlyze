from collections import deque
S = input()
Q = int(input())
Query = [input().split() for _ in range(Q)]
s = list(S)
d = deque(s)
d_is_reversed = False
for j in range(Q):
    if Query[j][0] == '1':
        d_is_reversed = not d_is_reversed
    elif Query[j][1] == '1':
        if d_is_reversed == False:
            d.appendleft(Query[j][2])
        else:
            d.append(Query[j][2])
    else:
        if d_is_reversed == False:
            d.append(Query[j][2])
        else:
            d.appendleft(Query[j][2])
if d_is_reversed == True:
    d.reverse()
printed = ''.join(d)
print(printed)
