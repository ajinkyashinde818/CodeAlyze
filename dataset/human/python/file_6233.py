def e_payment_greedy():
    N = [int(i) for i in list(input())]
    s = N[::-1] + [0]  # [-d-1]: 最終的に 10**d 円札を何枚受渡ししたかが格納される

    for i in range(len(N)):
        if s[i] >= 6 or (s[i] == 5 and s[i + 1] >= 5):
            s[i] = 10 - s[i]
            s[i + 1] += 1
    return sum(s)

print(e_payment_greedy())
