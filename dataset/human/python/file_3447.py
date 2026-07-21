from collections import Counter
num = int(input())
def pr(n):
   a = []
   while n % 2 == 0:
        a.append(2)
        n //= 2
   f = 3
   while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
   if n != 1:
      a.append(n)
   return a
if num == 1:
   print(0)
   quit()
prm = Counter(pr(num)).items()
ans = 0
for el,nm in prm:
   x = 1
   while True:
      if nm >= x:
         nm -= x
         ans += 1
         x += 1
      else:
         break
print(ans)
