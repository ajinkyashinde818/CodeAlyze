import sys
import itertools

input = sys.stdin.readline


def main():
    D, G = [int(x) for x in input().split()]
    pc = []
    for _ in range(D):
        pc.append([int(x) for x in input().split()])

    ruiseki = []
    for i, v in enumerate(pc):
        ruiseki.append((i + 1) * v[0] * 100 + v[1])

    ans = float("inf")
    for i in itertools.product(range(3), repeat=D):
        tmp = 0
        c = 0
        x = []
        for j, v in enumerate(i):
            if v == 0:
                continue
            elif v == 2:
                tmp += ruiseki[j]
                c += pc[j][0]
            else:
                if pc[j][0] == 1:
                    continue
                x.append(j)

        while tmp < G and x:
            y = x.pop()
            if G - tmp > (pc[y][0] - 1) * (y + 1) * 100:
                tmp += (pc[y][0] - 1) * (y + 1) * 100
                c += pc[y][0] - 1
            else:
                z = -(-(G - tmp) // ((y + 1) * 100))
                c += z
                tmp += z * (y + 1) * 100

        if tmp >= G:
            ans = min(ans, c)

    print(ans)


if __name__ == '__main__':
    main()
