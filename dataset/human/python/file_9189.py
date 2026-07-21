import sys
input = sys.stdin.readline

S = list(reversed(input().strip()))
P = [list(reversed(v)) for v in ["dream", "dreamer", "erase", "eraser"]]

n = 0
while n < len(S):
    if S[n:n+5] == P[0] or S[n:n+5] == P[2]:
        n += 5
    elif S[n:n+7] == P[1]:
        n += 7
    elif S[n:n+6] == P[3]:
        n += 6
    else:
        print("NO")
        exit()
        
print("YES")
