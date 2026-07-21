def main():
    R, G, B, N = [int(x) for x in input().split()]

    ct = 0
    for r in range(N + 1):
        for g in range(N + 1):
            b = (N-R*r-G*g) / B
            if b < 0: break
            if (b % 1) == 0:
                ct += 1

    print(ct)

if __name__ == "__main__":
    main()
