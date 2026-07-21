import sys
input = sys.stdin.readline


def log(v):
    print(v, file=sys.stderr)


s = sorted(input().strip())
t = sorted(input().strip())
t.reverse()

for i in range(0, max(len(s), len(t))):
    if len(s) <= i:
        print("Yes")
        exit(0)
    if len(t) <= i:
        print("No")
        exit(0)
    if s[i] > t[i]:
        print("No")
        exit(0)
    if s[i] < t[i]:
        print("Yes")
        exit(0)
print("No")
