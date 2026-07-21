INF = 999999999999999999L
EPS = 1e-12

def read():
    return raw_input().strip()

def read_ints():
    return map(int,read().split())

n = int(read())
s = read()
cnts = [0]*26 
for c in s:
    cnts[ord(c)-ord("a")] += 1
# print cnts 

ans = 1
for i in range(26):
    ans = ans * (cnts[i]+1) 
ans -= 1 
print ans % (10**9+7)
