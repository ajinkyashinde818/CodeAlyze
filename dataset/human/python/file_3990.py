from bisect import bisect_right

N = int(input())
Nroot = int(N**(1/2))

an = [i*(i+1)//2 for i in range(50)]

ans = 0
for i in range(2, Nroot):
  count = 0
  if N%i == 0:
    Ni = N//i
    count = 1
    while Ni%i == 0:
      count += 1
      Ni = Ni//i
      
    ans += bisect_right(an, count) -1
    
  N = N//(i**count)
  
if N>1:
  print(ans+1)
else:
  print(ans)
