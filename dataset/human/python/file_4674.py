def decode(s):
    ret = 0
    u = 1
    for c in 'ixcm':
        i = s.find(c)
        if i < 0:
            pass
        elif i == 0 or not s[i-1].isdigit():
            ret += u
        else:
            ret += u * int(s[i-1])
        u *= 10
    return ret

def encode(n):
    ret = ''
    for c in 'ixcm':
        d = n % 10
        if d == 1:
            ret = c + ret
        elif d > 1:
            ret = str(d) + c + ret
        n //= 10
    return ret

N = int(input())
for i in range(N):
    a,b = input().split()
    print(encode(decode(a) + decode(b)))
