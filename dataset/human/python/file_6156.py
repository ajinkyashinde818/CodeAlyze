def poison():
    sum = input()
    sum = sum.split()
    for i in range(3):
        sum[i] = int(sum[i])
        if 0 > sum[i] or sum[i] > 10 ** 9:
            return print("error")

    notPoison = sum[0] + sum[1]
    if (notPoison + 1) >= sum[2]:
        sum[1] += sum[2]
    else:
        sum[1] += notPoison + 1
    return print(sum[1])


poison()
