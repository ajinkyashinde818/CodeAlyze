import sys
read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7

def main():
    n = int(input())
    S = input()
    L = [0] * 26

    for s in S:
        L[ord(s) - 97] += 1

    ans = 1
    for i in range(26):
        if L[i] != 0:
            ans = (ans * (L[i] + 1)) % (10 ** 9 + 7)

    print(ans - 1)


if __name__ == '__main__':
    main()
