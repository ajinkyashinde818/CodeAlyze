S = str(input())
S = S[::-1]

def solve(S):
    sl = 0
    while True:
        if len(S) == sl:
            return True
        if S[sl:sl+7] in {"remaerd"}:
            sl += 7
        elif S[sl:sl+6] in {"resare"}:
            sl += 6
        elif S[sl:sl+5] in {"maerd","esare"}:
            sl += 5
        else:
            return False
if solve(S):
    print("YES")
else:
    print("NO")
