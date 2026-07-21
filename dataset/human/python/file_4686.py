mcxi = {"m": 1000, "c": 100, "x": 10, "i": 1}
nums = [str(i) for i in range(2, 10)]

def calc(s):
    tmp = 0
    while s:
        c = s.pop()
        if c in nums:
            a = int(c)
            if len(s) == 0:
                tmp += a
                break
            c = s.pop()
            tmp += a * mcxi[c]
        else:
            tmp += mcxi[c]
    return tmp

n = int(input())
for _ in range(n):
    mcxis = input().split()
    a = ' '.join(mcxis[0]).split()[::-1]
    b = ' '.join(mcxis[1]).split()[::-1]
    tmp = calc(a) + calc(b)
    m, tmp = divmod(tmp, 1000)
    c, tmp = divmod(tmp, 100)
    x, i = divmod(tmp, 10)
    ans = ""
    if m > 0:
        ans += str(m)+"m"
    if c > 0:
        ans += str(c)+"c"
    if x > 0:
        ans += str(x)+"x"
    if i > 0:
        ans += str(i)+"i"
    print(ans.replace("1", ""))
