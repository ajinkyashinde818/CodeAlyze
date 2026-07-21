def main():
    from itertools import product

    D, G = map(int, input().split())

    prob = []
    for j in range(1, D + 1):
        p, c = map(int, input().split())
        prob.append((j * 100, p, c))  # score,amount,bonus

    ans = -1
    for prd in product([0, 1], repeat=D):
        cnt = 0
        g = 0
        for j, (score, amount, bonus) in zip(prd, prob):
            if j:
                cnt += amount
                g += score * amount + bonus

        if g < G:
            for j, (score, amount, bonus) in reversed(tuple(zip(prd, prob))):
                if (not j) and (score * amount >= G - g):
                    use = (G - g + score - 1) // score
                    cnt += use
                    g += score * use
                    break

        if (g < G) or (~ans and ans <= cnt): continue
        ans = cnt

    print(ans)


if __name__ == '__main__':
    main()
