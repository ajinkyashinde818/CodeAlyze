import sys

s = sys.stdin.readline().rstrip()
q = int(sys.stdin.readline().rstrip())
query = [sys.stdin.readline().rstrip().split() for i in range(q)]
top = 1
s = list(s)
s_front = []
s_back = []
for i in range(q):
    que = query[i]
    if que[0] == '1':
        top *= -1
    else:
        if que[1] == '1':
            if top > 0:
                s_front.append(que[2])
                # s = ''.join([que[2], s])
                # s = que[2] + s
            else:
                s_back.append(que[2])
                # s = ''.join([s, que[2]])
                # s = s + que[2]
        else:
            if top > 0:
                s_back.append(que[2])
                # s = ''.join([s, que[2]])
                # s = s + que[2]
            else:
                s_front.append(que[2])
                # s = ''.join([que[2], s])
                # s = que[2] + s
s_front.reverse()
s_front.extend(s)
s_front.extend(s_back)
s = s_front
s = ''.join(s)
if top < 0:
    s = s[::-1]
print(s)
