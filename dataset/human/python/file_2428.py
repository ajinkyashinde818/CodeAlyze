import math


def main():

    num, goal = map(int, input().split())
    data = [list(map(int, input().split())) for i in range(num)]

    ans = 10 ** 10

    for i in range(2 ** num):
        toku_flg = list(map(int, list(bin(i)[2:])))
        toku_flg = [0 for i in range(num - len(toku_flg))] + toku_flg

        now_score = 0
        now_mondai = 0
        for i in range(num):
            if toku_flg[i] == 1:
                now_score += (i + 1) * 100 * data[i][0] + data[i][1]
                now_mondai += data[i][0]

        if now_score < goal:
            for i in range(num)[::-1]:
                if toku_flg[i] == 0:
                    if now_score + (i + 1) * 100 * (data[i][0] - 1) < goal:
                        break
                    nokori = goal - now_score
                    add_num = math.ceil(nokori / ((i + 1) * 100))
                    now_score += (i + 1) * 100 * add_num
                    now_mondai += add_num
                    break

        if now_score >= goal:
            if now_mondai < ans:
                ans = now_mondai

    print(ans)





if __name__ == '__main__':
    main()
