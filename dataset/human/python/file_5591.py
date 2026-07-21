def solve(s):
    n = len(s)
    t = "".join(filter(lambda _: _!= "x", s))
    if t != t[::-1]:
        return -1
    l = 0
    r = n-1
    res = 0
    while l < r:
        nl = 0
        while (l < r) and (s[l] == "x"):
            nl += 1
            l += 1
        nr = 0
        while (l < r) and (s[r] == "x"):
            nr += 1
            r -= 1
        if (s[l] == s[r]) and (s[l] != "x"):
            res += abs(nl - nr)
        l += 1
        r -= 1
    return res

assert solve("xabxa") == 2
assert solve("ab") == -1
assert solve("a") == 0
assert solve("oxxx") == 3
assert solve("axxxa") == 0

s = input()
print(solve(s))
