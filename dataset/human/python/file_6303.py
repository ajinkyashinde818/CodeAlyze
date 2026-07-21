import sys

n=sys.stdin.readline().rstrip()[::-1]
to=0

m=0
n+="0"
num=len(n)

for i in range(num):
    k=int(n[i])
    k+=m
    if k==5:
        if int(n[i+1])>=5:
            to+=10-k
            m=1
        else:
            to+=k
            m=0
    if k<5:
        to+=k
        m=0
    elif k>5:
        to+=10-k
        m=1
        
print(to+m)
