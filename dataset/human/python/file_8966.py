import sys
input = sys.stdin.readline

def main():
    S = input().strip()

    n = len(S)

    while n > 0:
        if S[n - 5:n] == "dream":
            n -= 5
        elif S[n - 5:n] == "erase":
            n -= 5
        elif S[n - 7:n] == "dreamer":
            n -= 7
        elif S[n - 6:n] == "eraser":
            n -= 6
        else:
            print("NO")
            return
    else:
        print("YES")


if __name__ == '__main__':
    main()
