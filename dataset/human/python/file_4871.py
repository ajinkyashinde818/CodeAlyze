import sys

input = sys.stdin.readline


def main():
    S = list(input().strip())
    T = list(input().strip())

    S.sort()
    T.sort(reverse=True)

    for s, t in zip(S, T):
        if ord(t) > ord(s):
            print("Yes")
            return
        if ord(s) > ord(t):
            print("No")
            return
    else:
        if len(T) > len(S):
            print("Yes")
        else:
            print("No")



if __name__ == '__main__':
    main()
