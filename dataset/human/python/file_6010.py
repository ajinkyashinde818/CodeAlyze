import sys
N = int(input())
array_a = list(map(int,input().split()))
array_b = list(map(int,input().split()))
array_c = list(map(int,input().split()))

if not ( 2 <= N <= 20 ):sys.exit()
if not ( 1 <= min(array_a) and max(array_a) <= N ): sys.exit()
if not ( 1 <= min(array_b) and max(array_b) <= 50 ): sys.exit()
if not ( 1 <= min(array_c) and max(array_c) <= 50 ): sys.exit()

confortable = 0
before = -1
for I in range(len(array_a)):
    pos = array_a[I]
    confortable += array_b[pos-1]
    if before + 1 == array_a[I]:
        confortable += array_c[before-1]
    before = array_a[I]
print(confortable)
