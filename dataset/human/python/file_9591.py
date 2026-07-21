def f(x):
    return int(x)-1
n,k=map(int,input().split())
A=list(map(f,input().split()))
B=[-1]*n
a=0
i=0
while True:
    if B[a]!=-1:
        j=B[a]
        break
    i+=1
    B[a]+=i
    a=A[a]
if k<i:
    print(B.index(k)+1)
else:
    k=(k-j)%(i-j)+j
    print(B.index(k)+1)
