import sys
input = lambda: sys.stdin.readline().rstrip()

def main():
    s = input()
    while True:
        if len(s) >= 5:
            if s[-5:] == 'dream' or s[-5:] == 'erase':
                s = s[:-5]
            elif s[-6:] == 'eraser':
                s = s[:-6]
            elif s[-7:] == 'dreamer':
                s = s[:-7]
            else:
                print('NO')
                return
            if s == '':
                print('YES')
                return
        else:
            print('NO')
            return

if __name__ == '__main__':
    main()
