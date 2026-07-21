def combinations(R, G, B, N):
    R, G, B, N = int(R), int(G), int(B), int(N)
    sorted_tuple = sorted((R, G, B), reverse=True)
    R = sorted_tuple[0]
    G = sorted_tuple[1]
    B = sorted_tuple[2]
    number_combos = 0

    for x in range(N // R + 1):
        for y in range((N - R * x) // G + 1):
            if (N - R * x - G * y) % B == 0:
                number_combos += 1
        
    return number_combos

R, G, B, N = input().split(' ')
print(combinations(R, G, B, N))
