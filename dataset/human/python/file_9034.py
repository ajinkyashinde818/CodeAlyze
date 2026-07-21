import sys
input = sys.stdin.readline
S = input().rstrip()

while S:
    if S[-5:] == "dream":
        S = S[:-5]
    elif S[-5:] == "erase":
        S = S[:-5]
    elif S[-6:] == "eraser":
        S = S[:-6]
    elif S[-7:] == "dreamer":
        S = S[:-7]
    else:
        print("NO")
        sys.exit()
print("YES")
