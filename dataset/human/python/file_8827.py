k, n = map(int, input().split())
A_1 = list(map(int, input().split()))

def calc_add(N):
    return N + k

A_2 = list(map(calc_add, A_1))

A_total = A_1 + A_2

min_d = k

i = 0
while i < n:
    if A_total[i + n -1] - A_total[i] <= min_d:
        min_d = A_total[i + n -1] - A_total[i]
    
    i += 1

print(min_d)
