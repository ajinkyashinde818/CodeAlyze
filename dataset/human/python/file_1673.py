N, M = map(int, input().split())
a = list(str(input()) for _ in range(N))
b = list(str(input()) for _ in range(M))

import sys
c = N-M + 1

for a_j in range(c):
    for start_a in range(c):
        for a_i, b_i in zip(range(start_a, start_a+M), range(M)):
            if a[a_i][a_j:a_j+M] == b[b_i]:
                is_match = True
            else:
                is_match = False
                break
        if is_match:
            print("Yes")
            sys.exit()

print("No")
