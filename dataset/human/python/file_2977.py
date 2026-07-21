n = int(input())

def trial_division(n):
    if n < 2:
        return []
    res = []
    tmp = n
    for i in range(2, int(n**0.5)+1):
        c = 0
        if tmp%i == 0:
            while tmp%i == 0:
                c += 1
                tmp //= i
            res.append([i, c])
    if tmp != 1:
        res.append([tmp, 1])
    return res

div = trial_division(n)
c = 0
for d in div:
    k = d[1]
    i = 1
    while k-i >= 0:
        c += 1
        k -= i
        i += 1
print(c)
