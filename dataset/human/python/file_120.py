import math
R, G, B, N = map(int, input().split())
ans = 0
cr = math.ceil(N/R)
cg = math.ceil(N/G)
cb = math.ceil(N/B)
for i in range(cr + 1):
    for j in range(cg + 1):
        tmp =  i * R + j * G
        if N - tmp >= 0 and (N - tmp) % B == 0:
           ans += 1
        elif N - tmp < 0:
          break
print(ans)
