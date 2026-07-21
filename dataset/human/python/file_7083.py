import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    S = input()
    Q = int(input())

    reverse = False
    header = [''] * Q
    footer = [''] * Q
    for i in range(Q):
        query = input()
        if query[0] == '1':
            reverse = not reverse
        else:
            _, f, c = query.split()
            isHead = f == '1'
            if reverse:
                isHead = not isHead
            if isHead:
                header[i] = c
            else:
                footer[i] = c

    if reverse:
        print("".join(footer[::-1] + list(S)[::-1] + header))
    else:
        print("".join(header[::-1]) + S + "".join(footer))

if __name__ == '__main__':
    main()
