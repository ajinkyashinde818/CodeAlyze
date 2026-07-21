import sys

def input():
    return sys.stdin.readline().rstrip()

if __name__ == "__main__":
    sl = sorted([ord(i) - 97 for i in input()])
    tl = sorted([ord(i) - 97 for i in input()], reverse=True)

    for s, t in zip(sl, tl):
        if s == t:
            continue
        elif s < t:
            print("Yes")
            exit()
        else:
            print("No")
            exit()

    print("Yes" if len(sl) < len(tl) else "No")
