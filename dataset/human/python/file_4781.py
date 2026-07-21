import sys
input = sys.stdin.readline


def read():
    S = input().strip()
    T = input().strip()
    return S, T


def solve(S, T):
    s = ''.join(sorted(S))
    t = ''.join(reversed(sorted(T)))
    return "Yes" if s < t else "No"


if __name__ == '__main__':
    inputs = read()
    outputs = solve(*inputs)
    if outputs is not None:
        print("%s" % str(outputs))
