from collections import deque

def T2F1(org_S,rev_S, C, jdg):
    if jdg%2 == 0:
        org_S.appendleft(C)
        rev_S.append(C)
        return org_S, rev_S
    else:
        org_S.append(C)
        rev_S.appendleft(C)
        return org_S, rev_S
def T2F2(org_S, rev_S, C,jdg):
    if jdg%2 == 0:
        org_S.append(C)
        rev_S.appendleft(C)
        return org_S, rev_S
    else:
        org_S.appendleft(C)
        rev_S.append(C)
        return org_S, rev_S
    
org_S = deque(list(input()))
rev_S = deque(list(reversed(org_S)))
Q = int(input())
jdg = 0

for i in range(Q):
    A = list(input().split())
    if A[0] == "1":
        jdg += 1
    elif A[1] == "1":
        T2F1(org_S, rev_S, A[2],jdg)
    else:
        T2F2(org_S, rev_S, A[2],jdg)
        
if jdg%2 ==0:
    org_S = "".join(org_S)
    print(org_S)
    
else:
    rev_S = "".join(rev_S)
    print(rev_S)
