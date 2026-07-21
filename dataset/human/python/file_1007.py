def resolve():
    n = int(input())
    s_list = list(input())
    mod = 10 ** 9 + 7

    if s_list[0] == "W" or s_list[-1] == "W":
        print(0)
        return

    from math import factorial

    l_counter = 0
    res = 1

    for i in range(2 * n):
        s = s_list[i]
        if i % 2 == 0:
            s = "W" if s == "B" else "B"

        if s == "W":
            l_counter += 1
        else:
            res = res * l_counter % mod
            l_counter -= 1
            if l_counter < 0:
                print(0)
                return

    if l_counter != 0:
        print(0)
    else:
        print(res * factorial(n) % mod)
        
resolve()
