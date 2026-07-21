def answer(R, G, B, N):
    r_count = N // R
    g_count = N // G
    ans = 0
    for i in range(r_count+1):
        for j in range(g_count+1):
            k = N - (R * i) - (G * j)
            if k < 0: continue
            if k % B == 0: ans += 1
    return ans  
    
R, G, B, N = map(int, input().split())
print(answer(R, G, B, N))
