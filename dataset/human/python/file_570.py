from sys import stdin

N = int(stdin.readline().rstrip())
A = [int(x) for x in stdin.readline().rstrip().split()]
if 0 in A:
    print(sum([abs(x) for x in A]))
    exit()
minus = [x for x in A if x < 0]
if len(minus) % 2 == 0:
    print(sum([abs(x) for x in A]))
else:
    absolute = sorted([abs(x) for x in A])
    print(sum(absolute) - 2 * absolute[0])
