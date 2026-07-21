import sys

def read():
    return sys.stdin.readline().strip()

def main():
    s = read()
    pre = ""
    sur = ""
    rev = False
    for _ in range(int(read())):
        q = read()
        if q == "1":
            rev = not rev
            continue
        _, f, c = q.split()
        if rev ^ (f == "1"):
            pre += c
        else:
            sur += c
    print((pre[::-1] + s + sur)[::1 - 2 * rev])

if __name__ == '__main__':
    main()
