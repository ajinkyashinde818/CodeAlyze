def findKey(C, x):
    for i, c in enumerate(C):
        if c == x:
            return i

    return None
    

N,K = map(int, input().split())
A = list(map(int, input().split()))

C = [None]*(N)

p = 1
c = 0
C[p-1] = c

while True:
    p = A[p-1]
    c += 1

    if C[p-1] != None:
        break

    C[p-1] = c

start = C[p-1]
cycle = c - start

# print(C,c1, c2)

if K <= start:
    print(findKey(C, K)+1)
else:
    print(findKey(C, (K-start)%cycle+start)+1)
