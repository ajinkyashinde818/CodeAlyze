import collections
N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A1 = collections.Counter(A)
B1 = collections.Counter(B)
A2 = A1.most_common()
B2 = B1.most_common()

if A2[0][0] == B2[0][0]:
  if min(A2[0][1], B2[0][1]) > int(N / 2):
    print("No")
    quit()

B.reverse()    
s = 0
t = N - 1
for i in range(N):
  if A[i] == B[i]:
    if (A[s] != B[i]) and (A[i] != B[s]):
      x = B[s]
      B[s] = B[i]
      B[i] = x
      s += 1
    elif (A[t] != B[i]) and (A[i] != B[t]) :
      x = B[t]
      B[t] = B[i]
      B[i] = x
      t -= 1
    else:
      print("No")
      quit()
  
#print(B)  
print("Yes")  
for i in range(N):
  print(B[i], end = " ")
print("")
