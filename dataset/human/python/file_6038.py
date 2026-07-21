import sys
def get_array(): return list(map(int, sys.stdin.readline().strip().split()))
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def input(): return sys.stdin.readline().strip()

n=int(input())
A=get_array()
B=get_array()
C=get_array()
score=0
for i in range(n):
  score+=B[A[i]-1]
  if i!=0:
    if A[i]==A[i-1]+1:
      score+=C[A[i-1]-1]
print(score)
