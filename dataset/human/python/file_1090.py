from collections import Counter
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
AC = Counter(A)
BC = Counter(B)
for i in BC.keys():
    if i in AC and BC[i] + AC[i] > N:
        print("No")
        exit()
AL,AR = {},{} 
BL,BR = {},{}
for i in range(N):
    if not A[i] in AL:
        AL[A[i]] = i
    AR[A[i]] = i

for i in range(N):
    if not B[i] in BL:
        BL[B[i]] = i
    BR[B[i]] = i
can = [1]*(N)

for i in BL.keys():
    if not i in AL:
        continue
    s = (N+AL[i]-BR[i])%N
    e = (N+AR[i]-BL[i])%N
    if e<s:
        e += N
    # print(i,s,e)
    for j in range(s,e+1):
        can[j%N] = 0

if 1 in can:
    print("Yes")
    ind = can.index(1)
    print(* (B+B)[N-ind:2*N-ind])
else:
    print("No")
