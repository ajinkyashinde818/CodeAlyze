"""
a=[0]*(n)
for i in range(n):
    if(i<2):
        a[i]=1
    else:
        a[i]=i*a[i-2]
for i in range(n):
    print(i,a[i]))
"""

def cal(n):
    res=0
    while(n>0):
        res+=n//5
        n//=5
    return res

n=int(input())
if(n==0):
    print(0)
elif(n%2==1):
    print(0)
else:
    print(cal(int(n//2)))
