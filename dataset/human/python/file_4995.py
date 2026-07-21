import sys
p=['41412121','41212141','21414121','21214141','14141212','14121214','12141412','12121414']
g=lambda x:map(int,x)
for e in sys.stdin:
 d={}
 for f in p:d[sum(s-t for s,t in zip(g(e.split()),g(f))if s>t)]=f
 print(*list(d[min(d)]))
