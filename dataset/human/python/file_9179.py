def main():
    s = input()
    while s:
        if s[-5:] == 'dream' or s[-5:] == 'erase':
            s = s[:-5]
        elif s[-6:] == 'eraser':
            s = s[:-6]
        elif s[-7:] == 'dreamer':
            s = s[:-7]
        else:
            break

    if s:
        print('NO')
    else:
        print('YES')


if __name__ == '__main__':
    main()
