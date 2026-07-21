def find(A,B,C):
    A=[x-1 for x in A]
    ans=B[A[len(A)-1]]
    for i in range(len(A)-1):
        now=A[i]
        next_one=A[i+1]
        if next_one==now+1:
            ans+=C[now]
        ans+=B[A[i]]
    return ans

N=int(input())
A=list(map(int,input().strip().split(" ")))
B=list(map(int,input().strip().split(" ")))
C=list(map(int,input().strip().split(" ")))

print(find(A,B,C))
