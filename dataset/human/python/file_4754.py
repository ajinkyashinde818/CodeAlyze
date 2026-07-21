import sys
read = sys.stdin.read
def main():
    s = list(input())
    t = list(input())
    s.sort()
    t.sort(reverse=True)
    s = "".join(s)
    t = "".join(t)
    if s < t:
        print('Yes')
    else:
        print('No')


if __name__ == '__main__':
    main()
