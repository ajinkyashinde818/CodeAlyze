from collections import Counter

N=int(input())
N_=N
f_=[]
for n in range(2,int(N**(1/2))+2):    
    while N_ % n==0: 
        N_=int(N_/n)
        f_.append(n)
        
if N_ != 1:
	f_.append(N_)
    
C=Counter(f_)
N_=N
ans=0
for c in C.keys():
    for c_ in range(1,C[c]+1):
        if N_ % c**c_ == 0:
            N_ = N_/c**c_
            ans+=1
if N==1:
    ans=0
print(ans)
