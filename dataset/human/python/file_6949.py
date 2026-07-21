def main():
    S = raw_input()
    Q = int(raw_input())

    is_reversed = False
    sentou = []
    owari = []

    for _ in range(Q):
        query = raw_input().split()
        if query[0] == "1":
            is_reversed = not is_reversed
        elif query[0] == "2":
            F = query[1]
            C = query[2]
            if F == "1":
                if not is_reversed:
                    sentou.append(C)
                else:
                    owari.append(C)
            elif F == "2":
                if not is_reversed:
                    owari.append(C)
                else:
                    sentou.append(C)

    S = "".join(sentou[::-1]+list(S)+owari)


    if not is_reversed:
        print S
    else:
        print S[::-1]

if __name__ == "__main__":
    main()
