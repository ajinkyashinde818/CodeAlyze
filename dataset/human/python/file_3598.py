from collections import Counter

def prime_factor(num):
  factor_list = []
  while num % 2 == 0:
    factor_list.append(2)
    num /= 2
  f = 3
  while f * f <= num:
    if num % f == 0:
      factor_list.append(f)
      num /= f
    else:
      f += 2
  if num!=1:
    factor_list.append(num)
  return factor_list

def get_count(c):
  ans = 0
  _max = c
  for i in range(1,c+1):
    if i <= _max:
      ans += 1
      _max -= i
    else:
      break
  return ans
a = int(input())
counter = Counter(prime_factor(a))
ans = 0
for i in counter:
  ans += get_count(counter[i])
print(ans)
