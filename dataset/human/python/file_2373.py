import math

def solve():
    [D,G] = [int(x) for x in input().split()]
    P = []
    C = []
    for _ in range(D):
        [p,g] = [int(x) for x in input().split()]
        P.append(p)
        C.append(g)

    LIM = 1 << D
    ans = 10**12  # INF 
    for bits in range(LIM):
        score = 0
        count = 0
        for i in range(D):
            maxi = -1
            if (bits >> i) & 1 == 1:
                # use all
                # print("useall", i, P[i])
                score += P[i] * 100 * (i+1) + C[i]
                count += P[i]

        if G <= score:
            # print("ans, count", ans, count)
            ans = min(ans, count)
            continue

        # use 中途半端
        for i in range(D):
            if (bits >> i) & 1 != 1:
                n = (G-score) / ((i+1)*100)
                # print("n", n)
                if n >= P[i]:
                    continue

                n = int(math.ceil(n))
                # print("cn", count + n)
                ans = min(ans, count + n)
    # print(ans)
    return ans


print(solve())
