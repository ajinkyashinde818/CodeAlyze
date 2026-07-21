import sys
sys.setrecursionlimit(100000)


def input():
    return sys.stdin.readline().strip()


def input_int():
    return int(input())


def input_int_list():
    return [int(i) for i in input().split()]


def main():
    S = input()
    # 後ろから貪欲に評価すればよい
    while True:
        if S[-5:] == "dream" or S[-5:] == "erase":
            S = S[:-5]
            continue
        elif S[-6:] == "eraser":
            S = S[:-6]
            continue
        elif S[-7:] == "dreamer":
            S = S[:-7]
            continue
        else:
            break
    if S == "":
        print("YES")
    else:
        print("NO")
    return


if __name__ == "__main__":
    main()
