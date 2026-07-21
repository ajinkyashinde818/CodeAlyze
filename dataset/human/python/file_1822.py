from itertools import product

n, m = [int(i) for i in input().rstrip().split()]
AA = [[0 if i == '.' else 1 for i in input().rstrip()] for _ in range(n)]
BB = [[0 if i == '.' else 1 for i in input().rstrip()] for _ in range(m)]

for i_r, i_c in product(range(n - m + 1), range(n - m + 1)):
    i_r -= 1
    i_c -= 1
    for k_r, k_c in product(range(m), range(m)):
        if AA[i_r + k_r][i_c + k_c] == BB[k_r][k_c]:
            continue
        else:
            break
    else:
        print('Yes')
        break
else:
    print('No')
