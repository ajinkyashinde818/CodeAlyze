from collections import Counter
import math
N=int(input())
s=[]
z=Counter()
def prime(a):
    i=2
    while i*i<=a:
        if a%i==0:return 0
        i+=1
    return 1

def vsum(a):
    s=0
    for i in range(1,a+1):
        s+=i
        if s==a:return i
        elif s>a:return i-1

if N==1:
    print(0)
    exit()
elif prime(N)==1:
    print(1)
    exit()

for i in range(2,int(math.sqrt(N))):
    while N%i==0:
        s.append(i)
        N=N//i
        if N==1:break
        elif prime(N)==1:
            s.append(N)
            break

z=Counter(s)
ans=0
for key,values in z.items():
    ans+=vsum(values)
print(ans)
