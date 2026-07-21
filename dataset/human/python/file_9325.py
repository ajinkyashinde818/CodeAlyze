N, K = [int(_) for _ in input().split()]
A = [int(_) for _ in input().split()]

def solve(N, K, A):
    result = 0
    cs = [-1] * N
    rs = []
    i = 0
    while i < K:
        if cs[result] != -1:
            l = i - cs[result]
            m = (K - (i + (K - i) // l * l)) 
            result = rs[-l + m]
            break
        cs[result] = i
        rs.append(result)
        result = A[result] - 1
        i += 1

    return result + 1

print(solve(N, K, A))
