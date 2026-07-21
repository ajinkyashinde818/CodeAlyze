"""
基本の差はable

 1  2 3  4 5
 4  5 1  2 3
+2  3 4  5 1

 7 10 8 11 9
sa3 -2 3 -2 -2

一度も選ばれてない=3
選ばれてる = -2
一回で -5・・・？
一回選ばれると本来あった +1が消えて -4される →よって-5
"""

import sys

N = int(input())

A = list(map(int,input().split()))

M = N*(N+1)//2

if sum(A) % M != 0:
    print ("NO")
    sys.exit()

able = sum(A) // M

#print (M,able)

A.append(A[0])
now = 0

for i in range(N):

    #print ((A[i+1]-A[i]-able)//N)

    if A[i+1] - A[i] == able:
        continue

    else:
        
        if ((A[i+1]-A[i])-able) % N != 0 or ((A[i+1]-A[i])-able) // N > 0:
            print ("NO")
            sys.exit()

        else:
            now += ((A[i+1]-A[i])-able) // (0-N)


if now == able:
    print ("YES")
else:
    print ("NO")
