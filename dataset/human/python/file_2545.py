import numpy as np

d,g=[int(c) for c in input().split(" ")]

p=[0]*(d+1)
c=[0]*(d+1)

for i in range(1,d+1):
    pp,cc=[int(c) for c in input().split(" ")]
    p[i]=pp
    c[i]=cc

def rec(i,g,flag):
    if i==d+1:
        cnt=0
        if g<=0:
            return 0

        for j in range(d,0,-1):
            bit=flag%2
            flag//=2

            if bit==0:
                ptsperprob=j*100
                psolved=min(p[j]-1,int(np.ceil(g/ptsperprob)))

                g-=psolved*ptsperprob
                cnt+=psolved

                if g<=0:
                    return cnt
        
        return 10000

    return min(p[i]+rec(i+1,g-c[i]-p[i]*100*i,2*flag+1),rec(i+1,g,2*flag))

print(rec(1,g,0))
