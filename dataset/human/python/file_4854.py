import sys
s=input()
t=input()

sn=[ord(s[i]) for i in range(len(s))]
tn=[ord(t[i]) for i in range(len(t))]

sn.sort()
tn.sort(reverse=True)

for i in range(min(len(tn), len(sn))):
    if tn[i] > sn[i]:
        print('Yes')
        sys.exit()
    elif tn[i] < sn[i]:
        print('No')
        sys.exit()

if len(tn) > len(sn):
    print('Yes')
else:
    print('No')
