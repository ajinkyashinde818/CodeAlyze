def main():
    s = open(0).read()
    b = s.count('-')
    z = s.count(' 0 ')
    _, *c, = map(int, s.replace('-', '').split())

    d = min(c)
    e = sum(c)

    if b % 2 == 0 or z > 0:
        print(e)
    else:
        print(e - 2 * d)


if __name__ == '__main__':
    main()
