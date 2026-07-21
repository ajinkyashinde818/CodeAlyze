from sys import stdin

N = int(stdin.readline())
A = list((int(wd) for wd in stdin.readline().split()))
B = list((int(wd) for wd in stdin.readline().split()))
C = list((int(wd) for wd in stdin.readline().split()))

ret = sum(B)
#print(ret)
for i in range(N-1):
    if A[i] + 1 == A[i+1]:
        #print(A[i], C[A[i]-1])
        ret += C[A[i]-1]
    pass
print(ret)
