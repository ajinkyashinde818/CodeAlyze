import re

S = input()
without_x = ''.join([s for s in S if s != 'x'])
if without_x != without_x[::-1]: print(-1)
elif S == S[::-1]: print(0)
else:
    ans = 0
    x_lists = re.split('[{}]'.format(''.join(list(set(without_x)))), S)
    n = len(x_lists); i = 0
    while i < n-1-i:
        ans += abs(len(x_lists[i]) - len(x_lists[n-1-i]))
        i += 1
    print(ans)
