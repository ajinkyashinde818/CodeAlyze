import sys
from itertools import zip_longest

s = input()
t = input()

tmp = list(s)
tmp.sort()
s_ = "".join(tmp)

tmp = list(t)
tmp.sort(reverse=True)
t_ = "".join(tmp)

st_ = [s_, t_]
st_.sort()

if s_ == t_:
    print("No")
elif st_[0] == s_:
    print("Yes")
else:
    print("No")
