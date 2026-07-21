import numpy as np
s = input()
q = int(input())
rbef = []
aft = []
sgn = 1
for i in range(q):
    qi = np.array(input().split(),dtype=str)
    if qi[0] == "1":
        sgn *= -1
    else:
        if (qi[1] == "1" or sgn == -1) and (qi[1] == "2" or sgn == 1):
            rbef.append(qi[2])
        else:
            aft.append(qi[2])

bef = "".join(reversed(rbef))
taft = "".join(aft)
ans = bef + s + taft

if sgn == 1:
    print(ans)
else:
    rans = ''.join(list(reversed(ans)))
    print(rans)
