import collections

s = input()

x_num = collections.deque()
x_num.append(0)
others = collections.deque()
for s_i in s:
    if s_i == 'x':
        x_num[-1] += 1
    else:
        others.append(s_i)
        x_num.append(0)
possible = 1
while len(others) > 1:
    if others.pop() != others.popleft():
        possible = 0
        break
if possible:
    ans = 0
    while len(x_num) > 1:
        ans += abs(x_num.pop() - x_num.popleft())
    print(ans)
else:
    print(-1)
