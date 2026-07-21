N = int(input())
n = input()    
m = n.split()
p = [int(i) for i in m]
list = 1
for i in range(N-1):
    list = (list * (i+1)) % 1000000007

def egcd(a, b):
    (x, lastx) = (0, 1)
    (y, lasty) = (1, 0)
    while b != 0:
        q = a // b
        (a, b) = (b, a % b)
        (x, lastx) = (lastx - q * x, x)
        (y, lasty) = (lasty - q * y, y)
    return (lastx, lasty, a)

# ax ≡ 1 (mod m)
def modinv(a, m):
    (inv, q, gcd_val) = egcd(a, m)
    return inv % m

A = 0
for i in range(N-1):
    if i == 0:
        A = (A + list * (p[N-1]-p[i])) % 1000000007
    else:
        A = (A + list * (p[N-1]-p[i]) * modinv(i+1,1000000007)) % 1000000007
print(A)
