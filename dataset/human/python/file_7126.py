from collections import deque
def main():
    s = list(input().rstrip())
    s = deque(s)
    q = int(input())
    f = True
    for _ in range(q):
        a = list(map(str, input().rstrip().split()))
        if a[0] == "1":
            if f:
                f = False
            else:
                f = True
        else:
            if a[1] == "1":
                if f:
                    s.appendleft(a[2])
                else:
                    s.append(a[2])
            else:
                if f:
                    s.append(a[2])
                else:
                    s.appendleft(a[2])
    if f:
        for c in s:
            print(c, end="")
    else:
        for c in reversed(s):
            print(c, end="")

if __name__ == "__main__":
    main()
