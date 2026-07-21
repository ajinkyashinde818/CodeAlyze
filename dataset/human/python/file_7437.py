from collections import deque
s = input()
q = int(input())
s = deque(s)
ans = []
ans_s = ''
one_count = 0
key = 0
for i in range(q):
    ans.append(list(input().split()))
for i in ans:
    if int(i[0])==1:
        one_count += 1
    else:
        if one_count%2==0:
            if int(i[1]) == 1:
                s.appendleft(i[2])
            else:
                s.append(i[2])
        else:
            if int(i[1]) == 1:
                s.append(i[2])
            else:
                s.appendleft(i[2])

if one_count%2==0:
    print(''.join(s))
else:
    print(''.join(s)[::-1])
