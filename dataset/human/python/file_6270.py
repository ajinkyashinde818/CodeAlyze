def main():
    N = input()
    reversed_N = ("0" + N)[::-1]

    kuriage = 0
    ans = 0
    for i in range(len(reversed_N)):
        n = int(reversed_N[i]) + kuriage

        if n < 5:
            ans += n
            kuriage = 0
        elif n == 5 and i < len(reversed_N) - 1:
            next_n = int(reversed_N[i + 1])
            if next_n < 5:
                ans += n
                kuriage = 0
            else:
                ans += 10 - n
                kuriage = 1
        else:
            ans += 10 - n
            kuriage = 1

    print(ans)


main()
