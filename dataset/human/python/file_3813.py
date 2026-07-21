n = int(input())

i = 2
cur_n = n
cnt = []
while i * i <= n:
    z = 0
    while cur_n % i == 0:
        z += 1
        cur_n //= i
    if z:
        cnt.append(z)
    i += 1

if cur_n != 1:
    cnt.append(1)

'''
ans_table = [0]
for i in range(40):
    ans_table[i // 2] + 1

[0, 1, 2
'''


def get_ans(power):
    i = 1
    res = 0
    while res + i <= power:
        res += i
        i += 1
    return i - 1


ans = 0
for v in cnt:
    ans += get_ans(v)


print(ans)
