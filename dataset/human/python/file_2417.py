def max_zero(t, n):
    if n % 2 == 1:
        n = (n-1) / 2
        t += 1
        return(max_zero(t, n))
    else:
        return t


d, g = [int(_) for _ in input().split()]
l = [0] * d
for i in range(d):
    p, c = [int(_) for _ in input().split()]
    all_score = (i+1)*100*p + c
    l[i] = [p, all_score]

n = 2**d
ans = float('inf')
for i in range(n):
    total = 0
    p_total = 0
    st = '0' + str(d) + 'b'
    n_bin = format(i, st)
    for j in range(d):
        if n_bin[j] == '1':
            total += l[j][1]
            p_total += l[j][0]
    if total >= g:
        ans = min(ans, p_total)
    else:
        b = g - total
        y = max_zero(0, i)
        a = d * 100 - 100 * y
        if b % a == 0:
            u = b // a
        else:
            u = (b // a) + 1
        if u <= l[d-1-y][0]-1:
            ans = min(ans, p_total + u)
print(ans)
