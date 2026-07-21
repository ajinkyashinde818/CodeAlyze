def count(l):
    res = {}
    for d in l:
        if d in res:
            res[d] += 1
        else:
            res[d] = 1
    return res

n = int(input())
string = input()
cnt = count(string)
mod = 10**9 + 7
ans = 1
for v in cnt.values():
    ans *= v + 1
    ans %= mod 
print(ans - 1)
