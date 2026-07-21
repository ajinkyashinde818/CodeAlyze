import numpy as np

n=int(input())
A=list(map(int,input().split()))
count=0
a_n=np.array(A)
abs_a=np.abs(a_n)
sum_a=np.sum(abs_a)
for x in A:
    if x<0:
        count+=1
if count%2==0:
    print(sum_a)
elif count%2==1:
    sum_b=sum_a-2*np.min(abs_a)
    print(sum_b)
