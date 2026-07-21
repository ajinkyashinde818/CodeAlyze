D, G = map(int, input().split())
pc = []
for i in range(D):
    pc.append(list(map(int, input().split())))


def convert(n):
    Bin = []
    while n != 0:
        a = n % 2
        n //= 2
        Bin.insert(0, a)
    if not Bin:
        Bin.append(0)
    return Bin


Min = 10**8
for i in range(0, 2**D):
    Bin = [str(s) for s in convert(i)]
    Bin = ''.join(Bin).zfill(D)
    idx = 0
    ct = 0
    score = 0
    for j in Bin:
        if j == '1':
            p, c = pc[idx]
            ct += p
            score += 100*(idx+1)*p+c
        if score >= G:
            Min = ct if ct < Min else Min
            break
        idx += 1
    if score < G:
        Bin = Bin[::-1]
        idx = 0
        for j in Bin:
            if j == '0':
                p, c = pc[idx]
                for k in range(p-1):
                    ct += 1
                    score += 100*(D-idx)
                    if score >= G:
                        Min = ct if ct < Min else Min
                        break
                score -= 100*(D-idx)*(p-1)
                ct -= (p-1)
            if score >= G:
                break
            idx += 1

print(Min)
