def gcd(n,m):
    while n > 0:
        a = n
        n = m % n
        m = a
    return m

R,G,B,N = map(int,input().split(" "))

C = G * B // gcd(G,B)

s = 0
b = 0
while b <= N:
    bb = b
    while bb <= N:
        if (N - bb) % B == 0:
            s += (N - bb) // C + 1
            bb = N + 1
        else:
            bb += G
    b += R

print(s)
