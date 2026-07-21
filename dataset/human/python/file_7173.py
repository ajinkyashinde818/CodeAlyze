from collections import deque

s = deque(input())
q = int(input())

rev_flag = False
for i in range(q):
    tmp_in = list(input().split())

    if tmp_in[0] == '1':
        if rev_flag:
            rev_flag = False
        else:
            rev_flag = True
    else:
        if rev_flag:
            if tmp_in[1] == '1':
                s.append(tmp_in[2])
            else:
                s.appendleft(tmp_in[2])
        else:
            if tmp_in[1] == '1':
                s.appendleft(tmp_in[2])
            else:
                s.append(tmp_in[2])

if rev_flag:
    s.reverse()

ans = "".join(s)
print(ans)
