from sys import stdin, setrecursionlimit


def main():
    input = stdin.readline
    s = list(input()[:-1])
    Q = int(input())
    reverse = False
    before = []
    after = []
    for _ in range(Q):
        q = list(map(str, input().split()))
        t = q[0]
        if t == '1':
            reverse = not (reverse)
        else:
            if reverse ^ (q[1] == '1'):
                before.append(q[2])
            else:
                after.append(q[2])
    if reverse:
        after.reverse()
        s.reverse()
        print(''.join(after + s + before))
    else:
        before.reverse()
        print(''.join(before + s + after))


if __name__ == "__main__":
    setrecursionlimit(10000)
    main()
