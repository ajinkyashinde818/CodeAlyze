import sys

def main():
    tmp = input().replace('\n','').split(' ')
    n = int(tmp[0])
    r = int(tmp[1])
    if n >= 10:
        print(r)
    else:
        res = r + 100 * (10-n)
        print(res)
if __name__ == '__main__':
    input = sys.stdin.readline
    main()
