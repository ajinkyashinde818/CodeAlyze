import copy
n, m = list(map(int, input().split()))
a = [list(map(int, input().split())) for _ in range(n)]
b = [((i+1)*100*name[0] + name[1]) for i, name in enumerate(a)]

ans = []
pat = []
for i in range(2**n):
    pat_c = []
    sum1 = 0
    count1 = 0
    for j in range(n):
        t = (i // 2 ** j) % 2
        pat_c.append(t)
        if  t == 1:
            sum1 += b[j]
            count1 += a[j][0]

    if sum1 < m and 0 in pat_c:
        tyuu1_index = len(pat_c) - pat_c[::-1].index(0) - 1
        tyuu1 = a[tyuu1_index]
        if (tyuu1_index + 1)*100*tyuu1[0] < (m - sum1):
            continue
        else:
            count1 += (m-sum1) // ((tyuu1_index + 1)*100)
            if (m-sum1) % ((tyuu1_index + 1)*100) != 0:
                count1 += 1
        ans.append(count1)
        pat.append(pat_c)
    else:
        ans.append(count1)
        pat.append(pat_c)

print(min(ans))
