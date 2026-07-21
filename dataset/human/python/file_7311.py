import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces

s = ns()
head = []
tail = []
rev = False
q = ni()
for i in range(q):
    cs = stdin.readline().rstrip().split()
    if cs[0] == "1":
        rev ^= True
        head, tail = tail, head
    else:
        if cs[1] == "1":
            head.append(cs[2])
        else:
            tail.append(cs[2])
print("".join(head[::-1]) + (s[::-1] if rev else s) + "".join(tail))
