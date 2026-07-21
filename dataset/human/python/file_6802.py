import sys
readline = sys.stdin.readline
sys.setrecursionlimit(20000)

def input():
    return readline().rstrip()

S = input()
Q = int(input())

prefix = []
suffix = []
flip = 0
for i in range(Q):
    T = input()
    if T == "1":
        prefix, suffix = suffix, prefix
        flip = 1 - flip
    else: # T == 2
        _, f, c = T.split()
        if f == "1":
            # 先頭に c 追加
            prefix.append(c)
        elif f == "2":
            # 末尾に c 追加
            suffix.append(c)

if flip == 1:
    S = S[::-1]
print("".join(prefix[::-1]), end="")
print(S, end="")
print("".join(suffix))
