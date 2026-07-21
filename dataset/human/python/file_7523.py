from collections import deque

s = input()
q = int(input())

inv_cnt = 0


li = []
r = []

for i in range(q):
    d = [x for x in input().split()]
    if d[0] == '1':
        inv_cnt += 1
        inv_cnt %= 2
    else:
        if inv_cnt == 0:
            if d[1] == '1':
                li.append(d[2])
            else:
                r.append(d[2])
        else:
            if d[1] == '1':
                r.append(d[2])
            else:
                li.append(d[2])

if inv_cnt == 0:
    print(''.join(li[::-1]) + s + ''.join(r))
else:
    print(''.join(r[::-1]) + s[::-1] + ''.join(li))
