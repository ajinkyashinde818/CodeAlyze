def f_c():
    n = int(input())
    s = input()
    q = 10**9 + 7

    stack, c = 0,1
    for i in range(2*n):
        if i % 2 == 0:
            if s[i] == "B":
                stack += 1
            else:
                c *= stack
                stack -= 1
        else:
            if s[i] == "B":
                c *= stack
                stack -= 1
            else:
                stack += 1
        c %= q
    if c == 0 or stack != 0:
        print(0)
    else:
        for i in range(1,n+1):
            c *= i
            c %= q
        print(c)

if __name__ == "__main__":
    f_c()
