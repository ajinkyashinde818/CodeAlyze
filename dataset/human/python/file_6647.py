def main():
    s = input()
    q = int(input())
    bottom = ''
    top = ''
    swapped = 0
    for _ in range(q):
        query = input()
        if len(query) == 1:
            swapped = 1 - swapped
            continue
        _, f, c = query.split()
        if swapped:
            if f == '1':
                bottom += c
            else:
                top += c
        else:
            if f == '1':
                top += c
            else:
                bottom += c

    if swapped:
        print(bottom[::-1] + s[::-1] + top)
    else:
        print(top[::-1]+s+bottom)


if __name__ == '__main__':
    main()
