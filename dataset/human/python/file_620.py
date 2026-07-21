import sys
input = sys.stdin.readline
N = int(input())
A = [int(x) for x in input().split()]

fn = 0
for a in A :
    if a < 0 :
        fn += 1

B = [abs(a) for a in A]
B.sort()
if fn%2 == 0 :
    print(sum(B))
else :
    print(sum(B) - B[0]*2)
