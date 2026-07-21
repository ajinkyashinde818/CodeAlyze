import sys
raw=[4,1,2,1,2,1,4,1]
for line in sys.stdin.readlines():
    p=map(int,line.strip().split())
    ma,ans=1<<30,str(1<<30)
    for i in xrange(8):
        t=raw[i:]+raw[:i]
        temp=sum(map(lambda a,b:a-b if a>b else 0,p,t))
        if (temp<ma) or (temp==ma and int(ans)>int("".join(map(str,t)))):
            ma=temp
            ans="".join(map(str,t))
    print " ".join(ans)
