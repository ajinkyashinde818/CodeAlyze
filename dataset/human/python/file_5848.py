N = int(input())
A = list(map(lambda x: int(x)-1,input().split()))
B = list(map(int,input().split()))
C = list(map(int,input().split()))

def it():
    for x,y in zip(A,A[1:]):
        if x+1 == y:
            yield C[x]
    for x in A:
        yield B[x]
print(sum(it()))
