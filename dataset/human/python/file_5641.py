import sys
from collections import Counter

s = input()
n = len(s)
ns = []
no = []

for i in range(n):
    if s[i] != "x":
        ns.append(s[i])
        no.append(i)
        
no = [-1] + no + [n]
        
m = len(no) 
sa = []
for i in range(m-1):
    sa.append(no[i+1] - no[i] - 1)
        
if ns != ns[::-1]:
    print(-1)
    sys.exit()
    
ans = 0
if m%2 == 1:
    mm = m//2
    te = no[mm]
    ans = 0
    for i in range(mm):
        ans += abs(sa[i]-sa[m-2-i])
else:
    mm = m//2
    te = no[mm]
    ans = 0
    for i in range(mm-1):
        ans += abs(sa[i]-sa[m-2-i])
        
print(ans)
