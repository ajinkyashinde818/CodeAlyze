N = int(input())


def simple_factrization(n):
    table = []  # 素因数を格納する
    temp = n    # nを素因数で割っていった値を一時的に格納する

    for i in range(2, int(n**0.5//1) + 1):
        if temp % i == 0:
            cnt = 0

            while temp % i == 0:
                cnt += 1
                temp //= i

            table.append([i, cnt])

    if temp != 1:
        table.append([temp, 1])

    if temp == []:
        table.append([n, 1])

    return table


f = simple_factrization(N)

count = 0
for i, f_i in enumerate(f):

    tmp_f_i = f_i[1]

    for j in range(1, f_i[1] + 1):
        tmp_f_i -= j
        if tmp_f_i < 0:
            break
        count += 1

print(count)
