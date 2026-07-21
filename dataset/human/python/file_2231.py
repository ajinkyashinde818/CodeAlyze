import sys


if __name__ == '__main__':
    D, G = map(int, input().split())
    p = ['-1'] * D
    c = ['-1'] * D
    for i in range(D):
        p[i], c[i] = map(int, input().split())

    answer = sys.maxsize
    for i in range(pow(2, D)):
        bonus_flags = format(i, "b").zfill(D)

        score = 0
        count = 0
        remain = []
        for index, bonus_flag in enumerate(bonus_flags):
            if bonus_flag == '1':
                score += (index + 1) * 100 * p[index] + c[index]
                count += p[index]
            else:
                remain.append(index)
        if score < G:
            R = G - score
            j = remain[-1]

            if (p[j] - 1) * (j+1) * 100 < R:
                continue
            count += -(-R//(100*(j+1)))
        answer = min(answer, count)

    print(answer)
