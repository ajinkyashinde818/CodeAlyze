n=int(input())
l=[0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, 66, 78, 91, 105, 120, 136, 153, 171, 190, 210, 231, 253, 276, 300, 325, 351, 378, 406, 435, 465, 496, 528, 561, 595, 630, 666, 703, 741, 780, 820] 
ans=0
from bisect import bisect_right as bl
from math import floor
for i in range(2,floor(n**(1/2))+1):
    if n%i:continue
    cnt=0
    while n%i==0:
        cnt+=1
        n//=i
    ind=bl(l,cnt)
    if ind==1:ans+=1
    else:
        ans+=ind-1
if n!=1:
    ans+=1
print(ans)
