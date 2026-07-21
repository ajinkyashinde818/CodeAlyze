from math import ceil

d, g = [int(x) for x in input().split()]

c_list = []
ans = 0
for i in range(d):
    p, c = [int(x) for x in input().split()]
    c_list.append((100 * (i + 1) * p + c, p))
    ans += p
c_list = list(reversed(c_list))

for i in range(2 ** d):
    s = 0
    temp_ans = 0
    flag = True
    for j in range(d):
        temp = (i >> j) & 1
        if temp == 1:
            s += c_list[j][0]
            temp_ans += c_list[j][1]
            if s >= g:
                break
        elif flag:
            k = j
            flag = False
    else:
        temp_s = (d - k) * 100
        temp = ceil((g - s) / temp_s)
        if  temp < c_list[k][1]:
            s += temp_s * temp
            temp_ans += temp
    if s >= g and temp_ans < ans:
        ans = temp_ans
print(ans)
