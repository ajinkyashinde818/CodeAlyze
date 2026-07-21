import sys
n=int(input())
A=list(map(int,input().split()))
count=0
for elem in A:
    if elem < 0:
        count+=1
if count%2==0:
    for i in range(len(A)):
        A[i]=abs(A[i])
    print(sum(A))
    sys.exit()
else:
    tmp=1000000000000
    for elem in A:
        tmp=(min(tmp,abs(elem)))
    for i in range(len(A)):
        A[i]=abs(A[i])
    print(sum(A)-2*tmp)
