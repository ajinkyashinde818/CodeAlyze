from bisect import bisect_right
a = int(input())

l = [1]
def fctr1(n): 
    f=[]
    c=0
    r=int(n**0.5)
    for i in range(2,r+2):
        while n%i==0:
            c+=1
            n=n//i
        if c!=0:
            f.append([i,c])
            c=0
    if n!=1:
        f.append([n,1])
    return f


f = fctr1(a)
ans = 0
# for i,j in f:
#     if 

for i in range(2,45):
    l.append(i+l[-1])
# print(l)
for i,j in f:
    a = bisect_right(l,j)
    # print(a)
    ans +=a

print(ans)
