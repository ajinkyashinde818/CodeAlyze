aa, bb = open(0).read().splitlines()

aa = sorted(aa)

bb = sorted(bb, reverse=True)

import sys
for a, b in zip(aa, bb):
    if a == b:
        continue
    else:
        if a<b:
            print('Yes')
            sys.exit()
        else:
            print('No')
            sys.exit()
        break
if len(aa)<len(bb):
    print('Yes')
else:
    print('No')
