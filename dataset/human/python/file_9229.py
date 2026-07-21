import sys


def solve(inp):
    S = inp.readline().rstrip()

    P = ['dream', 'dreamer', 'erase', 'eraser']

    S = ''.join(reversed(S))

    while len(S) > 0:
        f = 0
        for p in P:
            p_str = ''.join(reversed(p))
            if S.startswith(p_str):
                f = 1
                S = S[len(p):]
                break
        if f == 0:
            return "NO"

    return "YES"


def main():
    result = solve(sys.stdin)
    if result:
        print(result)


if __name__ == '__main__':
    main()
