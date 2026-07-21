import sys
sys.setrecursionlimit(10**6)
read = sys.stdin.read
readlines = sys.stdin.readlines
def main():
    s = input()
    words = ["dream","erase"]
    wordsr = ["dreamer", "eraser"]
    while s:
        if s[-7:] == "dreamer":
            s = s[:-7]
        elif s[-6:] == "eraser":
            s = s[:-6]
        elif s[-5:] in words:
            s = s[:-5]
        else:
            print('NO')
            sys.exit()
    print('YES')


if __name__ == '__main__':
    main()
