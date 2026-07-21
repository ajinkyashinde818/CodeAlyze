from collections import Counter
def factorization(n):
    a=[]
    for i in range(2,int(n**.5)+1):
        while n%i==0:
            n//=i
            a.append(i)
    if n!=1:
        a.append(n)
    return a
n=int(input())
A=factorization(n)
B=Counter(A)
count=0
for key,value in B.items():
    for i in range(1,value+1):
        if n%(key**i)==0:
            count+=1
            n//=(key**i)
        else:break
print(count)
