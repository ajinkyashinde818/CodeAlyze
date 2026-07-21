import sys
s=sys.stdin.readline().strip()

q=int(input())

p=1
front=''
back=''

for i in range(q):
    slst=input().split()

    if len(slst)==1:
        p*=-1
    else:
        t,f,c=slst

        f=int(f)

        if (f*2-3)*p==1:
            back=back+c
        else:
            front=c+front

s=front+s+back

if p==-1:
    s=s[::-1]

print(s)
