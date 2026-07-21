import sys
s = list(str(input()))
t = list(str(input()))
ss = sorted(s)
st = sorted(t)
rst = sorted(t, reverse=True)

if (len(s) < len(t)):
    if (''.join(ss) == ''.join(t[:len(s)])):
        print('Yes')
        sys.exit()
m = min(len(s), len(t))
for i in range(m):
    #print(ss[i] , rst[i])
    if (ss[i] < rst[i]):
        print('Yes')
        sys.exit()
print('No')
