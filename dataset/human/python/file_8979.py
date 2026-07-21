import sys

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60
MOD = 1000000007


def main():
    S = readline().strip()

    S = S[::-1]
    word = ['dream', 'dreamer', 'erase', 'eraser']
    word = [w[::-1] for w in word]

    ok = True
    i = 0
    while i < len(S):
        j = i
        for w in word:
            if all(w[j] == S[i + j] for j in range(len(w))):
                j += len(w)
                break
        if i == j:
            ok = False
            break
        i = j

    if ok:
        print('YES')
    else:
        print('NO')

    return


if __name__ == '__main__':
    main()
