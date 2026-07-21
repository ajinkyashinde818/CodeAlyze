import sys
def input(): return sys.stdin.readline().strip()


def main():
    s = list(input())
    t = list(input())
    s.sort()
    t.sort(reverse=True)
    if s < t:
        print("Yes")
    else:
        print("No")




if __name__ == "__main__":
    main()
