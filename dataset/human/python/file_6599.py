from collections import deque
S = deque([str for str in input()])
dic = 1
Q = int(input())
for i in range(0,Q):
    Query = input()
    if Query == '1':
        dic = dic*(-1)
    else:
        T, F, C = Query.split()
        if (int(F)*dic == 2) or (int(F)*dic == -1):
            S.append(C)
        else:
            S.appendleft(C)
print(''.join(list(S)[::dic]))
