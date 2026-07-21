INF = 999999999999999999L
EPS = 1e-12

def read():
    return raw_input().strip()

def read_ints():
    return map(int,read().split())

a,b,c = read_ints()
ans = 0
amt = min(b,c)
ans += 2*amt
b -= amt
c -= amt 

amt = min(a,c)
ans += amt
a -= amt 
c -= amt 
# print ans 

if c > 0:
    ans += 1
ans += b 
print ans
