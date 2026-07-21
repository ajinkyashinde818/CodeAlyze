d, g = map(int, input().split())

p, c = [], []
for _ in range(d):
     tp, tc = map(int, input().split())
     p.append(tp)
     c.append(tc)

ans = float("inf")
for bit in range(2 ** d):
    s_temp = 0
    p_temp = 0
    m_temp = -1
    for dd in range(d):
        if (bit >> dd) & 1:
            s_temp += p[dd] * (dd+1) * 100 + c[dd]
            p_temp += p[dd]
        else:
            m_temp = dd
            
    diff = g - s_temp
    
    if diff <= 0:
        ans = min(ans, p_temp)
    elif m_temp != -1:
        from math import ceil
        tt = ceil(diff / (m_temp+1) / 100)
        if tt <= p[m_temp]:
            ans = min(ans, p_temp + tt)

print(ans)
