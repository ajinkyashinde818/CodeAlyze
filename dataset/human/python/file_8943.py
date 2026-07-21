def main():
    S = input()
    w1 = 'dream'[::-1]
    w2 = 'dreamer'[::-1]
    w3 = 'erase'[::-1]
    w4 = 'eraser'[::-1]
    S = S[::-1]
    words = [w1, w2, w3, w4]

    i = 0
    while i != len(S):
        for w in words:
            if S[i:].startswith(w):
                i += len(w)
                break
        else:
            print("NO")
            exit()

    print("YES")



if __name__ == "__main__":
    main()
