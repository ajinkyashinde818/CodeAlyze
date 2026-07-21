import bisect
N,K=map(int,input().split())
A=list(map(int,input().split()))
index=[0]
index.append(A[0]-1)
tt=[A[0]-1]
flag=0
count=0
for _ in range(1,K):
    t=index[-1]
    ttt=bisect.bisect_left(tt, A[t]-1)

    if len(tt) > ttt and tt[ttt]==A[t]-1:
        index.append(A[t]-1)
        flag=1
        break
    index.append(A[t]-1)
    bisect.insort(tt,A[t]-1)
if flag==0:
    print(index[-1]+1)
    exit()
#print("a")
#print(index)
check = index[-1]
for i,c in enumerate(index):
    if c==check:
        a_path=i
        break
K-=a_path
t=len(index)-1-a_path
print(index[a_path+K%t]+1)
