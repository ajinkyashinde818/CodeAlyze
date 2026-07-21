N,M= list(map(int,input().split()))
import sys
A=set()
B=set()
l=[i.rstrip().split() for i in sys.stdin.readlines()]
for i,j in l:
   if i == "1":
      A.add(j)
   if j == str(N):
      B.add(i)
if len(A&B) > 0:
   print("POSSIBLE")
else:
   print("IMPOSSIBLE")
