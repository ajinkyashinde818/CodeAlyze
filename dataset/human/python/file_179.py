def gcd(s, t):
  if s < t:
    s, t = t, s
  if t == 0:
    return s
  else:
    return gcd(t, s % t)

R, G, B, N = map(int, input().split())
lcm = (G * B) // gcd(G, B)
r, g, b, ans = 0, 0, 0, 0
while r <= N:
  while r + g <= N:
    if (N - r - g) % B == 0:
      ans += 1
      ans += (N - r - g) // lcm
      break
    g += G
  g = 0
  r += R
print(ans)
