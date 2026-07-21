import sys

S = sys.stdin.readline().strip()

S = S[::-1]
i = 0
while i < len(S):
    if S[i:i+5] == "maerd":
        i += 5
    elif S[i:i+7] == "remaerd":
        i += 7
    elif S[i:i+5] == "esare":
        i += 5
    elif S[i:i+6] == "resare":
        i += 6
    else:
        break

if i == len(S):
    print("YES")
else:
    print("NO")
