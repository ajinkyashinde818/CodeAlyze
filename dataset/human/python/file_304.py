from fractions import gcd
def get_result(L, N):
    L_abs = [abs(x) for x in L]
    A = sum(L_abs)
    B = min(L_abs)
    neg_count = 0
    for elem in L:
        if elem < 0:
            neg_count += 1
    if neg_count % 2 == 0:
        return A
    else:
        return (A-2*B)


N = int(input())
L = [int(s) for s in input().split(" ")]
result = get_result(L, N)
print(result )
