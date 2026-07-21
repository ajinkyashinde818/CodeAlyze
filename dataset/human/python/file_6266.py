X = [0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0]
def solve(N):
    N = [int(c) for c in N][::-1]
    p = 0
    b = 0
    for i in range(len(N)):
        c = N[i] + b
        p += X[c]
        if c == 5:
            b = 0 if i == len(N)-1 or N[i+1] < 5 else 1
        else:
            b = c > 5
    return p + b

print(solve(input()))
