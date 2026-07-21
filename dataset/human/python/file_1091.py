import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))[::-1]
yaba = None
for i in range(N):
  if A[i]==B[i]:
    yaba = A[i]

if not yaba:
  print("Yes")
  print(*B)
  exit()

daijobu = []
for i in range(N):
  if A[i]!=yaba and B[i]!=yaba:
    daijobu.append(i)

for i in range(N):
  if A[i]==B[i]:
    if not daijobu:
      print("No")
      exit()
    else:
      p = daijobu.pop()
      B[i],B[p] = B[p],B[i]
      
print("Yes")
print(*B)
