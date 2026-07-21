WORDS = ['dream', 'dreamer', 'erase', 'eraser']
REVERSED_WORDS = [word[::-1] for word in WORDS]


def main(s):
    i = 0
    while i < len(s):
        for word in REVERSED_WORDS:
            if s[i:].startswith(word):
                i += len(word)
                break
        else:
            print('NO')
            break
    else:
        print('YES')


if __name__ == "__main__":
    main(input()[::-1])
