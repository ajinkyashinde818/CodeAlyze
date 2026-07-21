n=int(input())
from collections import defaultdict
def factorization(n):
    arr = defaultdict(int)
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr[i]+=cnt

    if temp!=1:
        arr[temp]=1

    if arr==[]:
        arr[n]=1

    return arr
l=factorization(n)
ans=0
for v in l.values():
    i=1
    while i<=v:
        ans+=1
        v-=i
        i+=1
print(ans)
