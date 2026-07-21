import sys
input = lambda: sys.stdin.readline().rstrip()
s=[i for i in input()]
x=0 ; st=[[],[]]
for _ in range(int(input())):
    inp=list(map(str,input().split()))
    if len(inp)==1: x^=1
    else: st[(int(inp[1])-1)^x].append(inp[2])
if x==0:
    st[0].reverse()
    ans=st[0]+s+st[1]
elif x==1:
    st[1].reverse()
    s.reverse()
    ans=st[1]+s+st[0]
print(''.join(ans))
