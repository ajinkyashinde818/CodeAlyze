import math

def factrization_prime(number):
    factor = {}
    div = 2
    s = math.sqrt(number)
    while div < s:
        div_cnt = 0
        while number % div == 0:
            div_cnt += 1
            number //= div
        if div_cnt != 0:
            factor[div] = div_cnt
        div += 1
    if number > 1:
        factor[number] = 1
    return factor

number = int(input())
factor = factrization_prime(number)
ans = 0
for i in factor.values():
  n = 0
  while n*(n+1)//2 <= i:
    n +=  1
  ans += n-1
print(ans)
