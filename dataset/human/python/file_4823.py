import sys
s = sys.stdin.readline().rstrip("\n")
t = sys.stdin.readline().rstrip("\n")
s_ = sorted(s)
s_ = ''.join(s_)
t_ = sorted(t, reverse=True)
t_ = ''.join(t_)
if s_ < t_:
    print('Yes')
else:
    print('No')
