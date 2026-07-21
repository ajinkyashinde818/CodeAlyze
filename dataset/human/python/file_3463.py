import math
def div(n):
    q=[]
    num=[]
    new=1
    while(new):
        orin=n
        for i in range(2,int(math.sqrt(n))):
            if n%i==0:
                q.append(i)
                num.append(0)
                curp = len(num)-1
                new=1
            while(n%i==0):
                n=n//i
                num[curp]+=1
        if orin==n:
            if n!=1:
                q.append(n)
                num.append(1)
            break
    return q,num

def check(num):
    i=1
    count=0
    while(num>=i):
        num-=i
        count+=1
        i+=1
    return count

n=int(input())
q,num=div(n)
if n==1:
    print(0)
else:
    total=0
    for i in range(len(num)):
        total+=check(num[i])
    print(total)
