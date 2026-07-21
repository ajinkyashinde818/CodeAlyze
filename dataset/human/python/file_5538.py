import sys

input = sys.stdin.readline


def main():
    x, y = input().split()
    table = {"A": 1, "B": 2, "C": 3, "D": 4, "E": 5, "F": 6}
    x = table[x]
    y = table[y]
    if x < y:
        print("<")
    elif x == y:
        print("=")
    else:
        print(">")


if __name__ == "__main__":
    main()
