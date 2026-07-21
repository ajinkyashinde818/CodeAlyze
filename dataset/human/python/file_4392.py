N=int(input())

def prime_pair(n):
    pairs = {}
    tmp = n
    for i in range(2, n):
        if i * i > n:
            break
        if tmp % i != 0:
            continue
        ex = 0
        while tmp % i == 0:
            ex += 1
            tmp /= i
        pairs[i] = ex
    if tmp != 1:
        pairs[int(tmp)] = 1
    return pairs

pp_n = prime_pair(N)
res = 0
for k in pp_n.keys():
    val = pp_n[k]
    power = 1
    while val >= power:
        val -= power
        power += 1
        res += 1

print(res)
