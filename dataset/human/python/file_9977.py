A, B = map(int, input().split())

def gcd(m, n):
    x = max(m, n)
    y = min(m, n)
    if x%y==0:
        return y
    else:
        while x%y!=0:
            z = x%y
            x = y
            y = z
        else:
            return z

def lcm(m, n):
    return int(m*n/gcd(m, n))

print(lcm(A, B))
