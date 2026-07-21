def main():
    md = 10 ** 9 + 7
    n = int(input())
    s = input()
    a = [c == "B" for c in s]
    B = True
    W = False
    a = [b if i % 2 else not b for i, b in enumerate(a)]
    if sum(a) != n:
        print(0)
        exit()
    ans = 1
    cnt_W = 0
    for b in a:
        if b == W:
            cnt_W += 1
        else:
            ans = (ans * cnt_W) % md
            cnt_W -= 1
            if ans == 0:
                print(0)
                exit()
    fac_n = 1
    for i in range(1, n + 1):
        fac_n = (fac_n * i) % md
    print((ans * fac_n) % md)

main()
