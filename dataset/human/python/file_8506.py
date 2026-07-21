K,N=map(int, input().split())
A=list(map(int, input().split()))

count = A[-1]-A[0]
def double(n):
     return n+K

B = map(double, A)
B = list(B)

i=0
while i<N-1:
    if B[i]-A[i+1] < count:
        count = B[i]-A[i+1]
    i+=1

print(count)
