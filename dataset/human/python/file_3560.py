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

N = int(input())
dic = factrization_prime(N)
ans = 0
for d in dic.keys():
    x = dic[d]
    minus = 1
    while(x>0):
        x -= minus
        minus += 1
        if x >= 0:
            ans += 1
print(ans)
