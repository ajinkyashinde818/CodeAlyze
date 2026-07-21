def main():
    N = [0] + [int(i) for i in input()]
    r = 0
    c = 0
    f = 0
    for i in reversed(N):
        if f:
            if i + c >= 5:
                c += 1
                r += 5
            else:
                r += 5
            f = 0
        i += c
        c = 0
        if i < 5:
            r += i
        elif i == 5:
            f += 1
        else:
            c += 1
            r += 10 - i
    print(r)



main()
