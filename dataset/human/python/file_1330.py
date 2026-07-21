from itertools import accumulate

n = int(input())
A = list(map(int, input().split()))

if n == 2:
  print(abs(A[0]-A[1]))
  exit()
  
B = list(accumulate(A))

ans = abs(B[-2]-A[-1])
y = 0
for i in range(len(A)-1, 0, -1):
    x = B[i-1]
    y += A[i]
    #print(x, y, ans)
    ans = min(ans, abs(x-y))

print(ans)
