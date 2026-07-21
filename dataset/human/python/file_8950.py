def main():
    S = input()
    words = ["dream", "dreamer", "erase", "eraser"]
    while len(S):
        ok = False
        for w in words:
            if S.endswith(w):
                S = S[:-len(w)]
                ok = True
                break
        if not ok:
            print("NO")
            return
    print("YES")


if __name__ == "__main__":
    main()
