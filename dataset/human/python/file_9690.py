def LIST():return list(map(int,input().split()))
def MAP():return map(int,input().split())

n,k=MAP()
a=LIST()
a=[0]+a
s=[0]
loca=1
begin=end=0
temp=[-1]*(2*10**5+1)
for i in range(1,n+1):
    s.append(a[loca])
    loca=a[loca]
    if k==i:
        print(s[i])
        exit()
    if temp[loca]==-1:
        temp[loca]=i
    else:
        begin=temp[loca]
        end=i-1
        break

if begin==0:print(s[(k-1)%n+1])
else:
    k=k-(begin-1)
    s=[0]+s[begin:]
    print(s[(k-1)%(end-begin+1)+1])
