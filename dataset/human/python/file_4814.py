import sys

readline = sys.stdin.readline
MOD = 10 ** 9 + 7
INF = float('INF')
sys.setrecursionlimit(10 ** 5)


def main():
    s = input()
    t = input()

    sl = list(s)
    sl.sort()
    st = list(t)
    st.sort(reverse=True)

    if sl < st:
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    main()
