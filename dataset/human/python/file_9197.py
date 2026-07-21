def read_input():
    s = input().strip()
    return s

def submit():
    s = read_input()
    rev_s = s[::-1]

    targets = ['dream', 'dreamer', 'erase', 'eraser']
    rev_targets = [t[::-1] for t in targets]

    while True:
        if not rev_s:
            print('YES')
            return

        for t in rev_targets:
            if rev_s.startswith(t):
                rev_s = rev_s[len(t):]
                break
        else:
            print('NO')
            return

if __name__ == '__main__':
    submit()
