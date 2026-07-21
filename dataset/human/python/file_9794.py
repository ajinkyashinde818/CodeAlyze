n,k=map(int,input().split())
a=list(map(int,input().split()))
l1=set([a[0]])
num1=a[0]
num2=1
l2=[]
def al(num):
    l1.add(num)
def n2(num5):
    return num5 in l1
for i in range(n):
    num1=a[num1-1]
    al(num1)
    if num2==len(l1):
        break
    else:
        num2=len(l1)
l1=list(l1)
num=l1.index(num1)
l2=l1[num:]
l1=l1[:num]
num1=len(l1)
num2=len(l2)
if k<=num1:
    print(l1[k-1])
else:
    num3=(k-num1)%num2
    print(l2[num3-1])
