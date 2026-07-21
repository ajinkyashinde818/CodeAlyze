import itertools

n = int(input())
a = list(map(int,input().split()))

su = sum(a)
ruisekiwa = list(itertools.accumulate(a))
ruisekiwa.pop()
ans = 10**99

for i in ruisekiwa:
  ans = min(ans,abs(su - 2*i))
  
print(ans)
