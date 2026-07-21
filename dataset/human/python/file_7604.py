import sys
input = sys.stdin.readline


def main():
    S = input().strip()
    Q = int(input())
    Query = [list(input().split()) for _ in range(Q)]
    reverse = 1
    head = ""
    tail = ""
    for T in Query:
        if T[0] == "1":
            if reverse == 1:
                reverse = 2
            else:
                reverse = 1
        elif T[0] == "2":
            if int(T[1]) == reverse:
                head = T[2] + head
            else:
                tail = tail + T[2]
    S = head + S + tail
    print(S) if reverse == 1 else print(S[::-1])


if __name__ == '__main__':
    main()
