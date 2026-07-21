import math
import sys

m=10**9 + 7 
sys.setrecursionlimit(1000010)
S = input()
Q = int(input())

inv = 0
head=[]
tail=[]
for _ in range(Q):
    q = input()
    if q == '1':
        inv = 1 - inv
    else:
        (T,F,C) = list(q.split())
        #print(T,F,C)
        if inv == 0:
            if F == '1':
                head.append(C)
            else:
                tail.append(C)
        else:
            if F == '1':
                tail.append(C)
            else:
                head.append(C)
    # print(head,S,tail)

if inv == 0:
    print(''.join(list(reversed(head))) + S + ''.join(tail))
else:
    print(''.join(list(reversed(tail))) + ''.join(list(reversed(S))) + ''.join(head))
