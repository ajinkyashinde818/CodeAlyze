from collections import Counter
def aprime_factorize(n: int) -> list:
    return_list = []
    while n % 2 == 0:
        return_list.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            return_list.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        return_list.append(n)
    return return_list

judge = []
cnt = 0
while len(judge) <= 40:
    for i in range(cnt+1):
        judge.append(cnt)
    cnt += 1
N = int(input())
list = Counter(aprime_factorize(N)).most_common()
res = 0
for i, li in enumerate(list):
    res += judge[li[1]]
print(res)
