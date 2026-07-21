import itertools

_N, _M = input().split()
N=int(_N)
M=int(_M)
A=[]
for i in range(0,N):
    A.append(input())
B=[]
for j in range(0,M):
    B.append(input())

ref_tuple = itertools.product(range(0,N-M+1),range(0,N-M+1))
t=False
for ref_row_a, ref_col_a in ref_tuple:
    for row_b, col_b in itertools.product(range(0,M),range(0,M)):
        if not A[ref_row_a+row_b][ref_col_a+col_b]==B[row_b][col_b]:
            break
        if (row_b, col_b)==(M-1,M-1):
            t=True
            break
    if t:
        break

if t:
    print('Yes')
else:
    print('No')
