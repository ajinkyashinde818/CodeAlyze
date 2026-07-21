w={"m":1000, "c":100, "x":10, "i":1}
def mcxiToNum(s):
    res=0
    while len(s)>0:
        if s[0] in w:
            res+=w[s[0]]
            s=s[1:]
        else:
            res+=w[s[1]]*int(s[0])
            s=s[2:]
    return res

def numToMcxi(n):
    s="ixcm"
    res=""
    for i in xrange(4):
        if n%10==0:
            res=res
        elif n%10==1:
            res=s[i]+res
        else:
            res=str(n%10)+s[i]+res
        n/=10
    return res

n=int(raw_input())
for _ in xrange(n):
    x,y=raw_input().split()
    print numToMcxi(mcxiToNum(x)+mcxiToNum(y))
