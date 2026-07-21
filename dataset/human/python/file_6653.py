def main():
    S = input()
    Q = int(input())
    reverse = False
    front = []
    back = []
    for _ in range(Q):
        TFC = list(input().split())
        if len(TFC) == 1:
            reverse = not(reverse)
        else:
            t,f,c = TFC
            if reverse:
                if f == "2":
                    front.append(c)
                else:
                    back.append(c)

            else:
                if f == "1":
                    front.append(c)
                else:
                    back.append(c)
    if reverse:
        print("".join(back[::-1]) + S[::-1] + "".join(front))
    else:
        print("".join(front[::-1]) + S + "".join(back))
    return

if __name__ == "__main__":
    main()
