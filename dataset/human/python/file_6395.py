def dobfac(num):
    count = 0
    i = 5
    if num % 2:
        print(0)
    else:
        while num / i > 0:
            count += num // i // 2
            i *= 5
        print(count)

if __name__ == "__main__":
    import sys
    in_str = []
    for line in sys.stdin:
        in_str.append(line)
    dobfac(int(in_str[0]))
