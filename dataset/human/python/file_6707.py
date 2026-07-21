from collections import deque

def main():
    s = input()
    q = int(input())

    Q = deque(s)
    rev = False
    for i in range(q):
        tfc = input().split()

        if tfc[0] == '1':
            rev = not rev
        else:
            f = tfc[1]
            c = tfc[2]
            if (f == '1' and not rev) or (f != '1' and rev):
                Q.appendleft(c)
            else:
                Q.append(c)

    if rev:
        print(''.join(list(Q)[::-1]))
    else:
        print(''.join(Q))

if __name__ == "__main__":
    main()
