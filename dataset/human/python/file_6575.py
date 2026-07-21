import copy
import math
import string

S = input()
Q = int(input())

is_reverse = False
front = ""
back = ""
for i in range(Q):
    A = list(map(str,input().split()))
    A[0] = int(A[0])
    if A[0] == 1:
        is_reverse = (not is_reverse)
    elif A[0] == 2:
        A[1] = int(A[1])
        if A[1] == 1:
            if is_reverse:
                back += A[2]
            else:
                front += A[2]
        else:
            if is_reverse:
                front += A[2]
            else:
                back += A[2]
front = front[::-1]
S = front + S + back
if is_reverse:
    S = S[::-1]
print(S)
