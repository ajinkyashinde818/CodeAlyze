import sys
def input(): return sys.stdin.readline().strip()


def main():
    x, y =input().split()
    if ord(x) < ord(y):
        print("<")
    elif ord(x) > ord(y):
        print(">")
    else:
        print("=")
    


if __name__ == "__main__":
    main()
