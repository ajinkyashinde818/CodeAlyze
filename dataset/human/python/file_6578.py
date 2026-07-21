import collections
s = input()
q = int(input())
back = 1
t = collections.deque()
for ss in s:
    t.append(ss)
for i in range(q):
    query = input().split()
    if query[0] == '1':
        back *= -1
    else:
        if query[1] == '1':
            if back == 1:
                t.appendleft(query[2])
            else:
                t.append(query[2])
        else:
            if back == 1:
                t.append(query[2])
            else:
                t.appendleft(query[2])
ans = ''
if back == -1:
    for i in range(len(t)):
        ans += t.pop()
else:
    for i in range(len(t)):
        ans += t.popleft()
print(ans)
