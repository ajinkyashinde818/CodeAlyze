from sys import exit, stdin
N, M = [int(_) for _ in stdin.readline().rstrip().split()]
s1 = set()
sn = set()
for _ in range(M):
    a,b = [int(_) for _ in stdin.readline().rstrip().split()]
    if a==1:
        s1.add(b)
    elif b==N:
        sn.add(a)
for x in s1:
    if x in sn:
        print("POSSIBLE")
        exit(0)
print("IMPOSSIBLE")
