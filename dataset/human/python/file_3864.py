import math
n = int(input())
q = int(math.sqrt(n))

ans = []
scores = []

div = 2
score = 0
while True:
  if div > q or div > n:
    if n != 1:
      ans.append(int(n))
      scores.append(1)
    break
  while n % div ==0:
    n /= div
    ans.append(div)
    score += 1
  else:
    div += 1
    if score > 0 :
      scores.append(score)
    score = 0
#print(ans,scores)

count = 0
for score in scores:
  i=1
  while score >= i:
    score -= i
    i += 1
    count += 1
print(count)
