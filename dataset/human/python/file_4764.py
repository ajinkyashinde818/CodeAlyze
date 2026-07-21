from sys import stdin

s = stdin.readline().rstrip()
t = stdin.readline().rstrip()

s_dash = ''.join(sorted(list(s)))
t_dash = ''.join(sorted(list(t), reverse=True))

if s_dash < t_dash:
    print('Yes')
else:
    print('No')
