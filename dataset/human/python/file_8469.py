from sys import stdin

lines = stdin.readlines()
k, n = [int(x) for x in lines[0].rstrip().split()]
a = [int(x) for x in lines[1].rstrip().split()]

diffs = [int(a[x+1]-a[x]) for x in range(len(a)-1)]
diffs.append(k - a[-1] + a[0])

print(k - max(diffs))
