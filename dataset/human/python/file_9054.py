def main():
    s = input()

    i = 0
    is_ok = True
    while i < len(s):
        if i <= len(s) < i + 7:
            if i <= len(s) < i + 4:
                is_ok = False
                break

        next_word = s[i:i+5]
        if next_word == 'dream':
            if s[i+5:i+7] == 'er':
                if s[i+7:i+8] == 'a':
                    # dream
                    i += 5
                else:
                    # dreamer
                    i += 7
            else:
                # dream
                i += 5
        elif next_word == 'erase':
            if s[i+5:i+6] == 'r':
                # eraser
                i += 6
            else:
                # erase
                i += 5
        else:
            is_ok = False
            break

    if is_ok:
        print('YES')
    else:
        print('NO')

def main2():
    s = input()
    i = len(s)
    while i > 0:
        if s[i-5:i] == 'dream':
            i -= 5
        elif s[i-7:i] == 'dreamer':
            i -= 7
        elif s[i-5:i] == 'erase':
            i -= 5
        elif s[i-6:i] == 'eraser':
            i -= 6
        else:
            break
    if i == 0:
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    #main()
    main2()
