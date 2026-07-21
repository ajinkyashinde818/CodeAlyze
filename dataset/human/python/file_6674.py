from collections import deque


def main():
    s = input()
    d = deque(s)
    q = int(input())
    reverse = False
    for _ in range(q):
        line = input().split()
        if line[0] == "1":
            reverse = reverse ^ True
        else:
            if (not reverse and line[1] == "1") or (reverse and line[1] == "2"):
                d.appendleft(line[2])
            else:
                d.append(line[2])
    print("".join(list(d)) if not reverse else "".join(list(reversed(d))))


if __name__ == "__main__":
    main()
