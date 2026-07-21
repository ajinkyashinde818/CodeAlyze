def count_line(l, k):
    i, p, c = l
    total = 0
    count = 0
    for j in range(p):
        if total >= k:
            return count
        
        total += i * 100
        count += 1
        if j == p - 1:
            total += c
    return count


def choice_line(i, f, total_count, total_score):
    f_copy = f.copy()
    if i == D:
        if total_score == G:
            m_c.append(total_count)
        elif total_score < G:
            for l in L:
                j = l[0]
                k = G - total_score
                if not j in f and k <= t_L[j-1]:
                    m_c.append(total_count + count_line(l, k))
        return
        
    choice_line(i + 1, f_copy, total_count, total_score)
    f_copy.append(i + 1)
    choice_line(i + 1, f_copy, total_count + L[i][1], total_score + t_L[i])


D, G = map(int, input().split())
L = []
t_L = []
m_c = []

for i in range(1, D + 1):
    p, c = map(int, input().split())
    L.append([i, p, c])
    total = p * i * 100 + c
    t_L.append(total)
   
choice_line(0, [], 0, 0)
print(min(m_c))
