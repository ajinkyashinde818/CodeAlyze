from statistics import median

R, G, B, N = [int(x) for x in input().split()]

count = 0
for r in range(N+1):
    for g in range(N+1):
        if (N - R*r - G*g) < 0:
            break
        if (N - R*r - G*g) % B == 0:
            count += 1

print(count)
