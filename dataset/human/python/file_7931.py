import sys
def input(): return sys.stdin.readline().strip()


def main():
    S = input()
    ans = set()
    for c in S: ans.add(c)
    if ans == {'a', 'b', 'c'}:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    main()
