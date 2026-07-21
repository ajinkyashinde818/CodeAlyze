from sys import stdin
 
s = stdin.readline().rstrip()
t = stdin.readline().rstrip()
s = sorted(s)
t = sorted(t,reverse =True)
tmp1 =("".join(s))
tmp2 =("".join(t))
if tmp1 < tmp2 :print('Yes')
else:print('No')
