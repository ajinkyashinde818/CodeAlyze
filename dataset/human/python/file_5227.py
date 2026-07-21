from operator import itemgetter

N,M=list(map(int,input().split()))
a = []
b = []
for i in range(M):
    a1,b1=[int(i) for i in input().split()]
    a.append(a1)
    b.append(b1)

l1=[i for i, x in enumerate(b) if x == N]
l2=[i for i, x in enumerate(a) if x == 1]

try:
    s1=itemgetter(*l1)(a)
except:
    s1=[]
try:
    s2=itemgetter(*l2)(b)
except:
    s2=[]

if type(s1) is int:
    tmp=s1
    s1=(tmp,)
if type(s2) is int:
    tmp=s2
    s2=(tmp,)

if len(set(s1)&set(s2))>0:
    print('POSSIBLE')
else:
    print('IMPOSSIBLE')
