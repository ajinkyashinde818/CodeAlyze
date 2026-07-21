import itertools
import functools
import math
from collections import Counter
from itertools import combinations

def CHK():
    S=list(input())
    Q=int(input())
    H=""
    B=""
    rflg = 0
    for i in range(Q):
        Que = input()
        if Que == '1':
            if rflg == 0:
                rflg = 1
            else:
                rflg = 0
            #S= list(reversed(S))
        else:
            T,F,C=map(str,Que.split())
            if F == '1' and rflg == 0 or (F != '1' and rflg == 1):
                #S=list(C)+S
                H = C + H
            else:
                #S.append(C)
                B = B + C

    S = list(H) + S + list(B)
    if rflg == 1:
        S = list(reversed(S))
    print("".join(S))

CHK()
