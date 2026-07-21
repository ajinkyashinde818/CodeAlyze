S = input().split(" ")
D = int(S[0])
G = int(S[1])

DATA = []
for i in range(D):
    DATA.append([int(s) for s in input().split(" ")])

def calculate(d, _g, data):
    counts = []
    for i in range(2 ** len(data)):
        arr = []
        bonusIndexes = []
        notBonusIndexes = []
        bonusSum = 0
        bonusCounts = 0
        for j in range(len(data)):
            s = i >> j & 1
            arr.insert(0,s)
            _j = len(data)-1 - j
            if s == 1:
                bonusIndexes.append(_j)
                bonusSum = bonusSum + (_j + 1) * 100 * data[_j][0] + data[_j][1]
                bonusCounts = bonusCounts + data[_j][0]
            else:
                notBonusIndexes.append(_j)

        g = _g

        if bonusSum >= g:
            # 该情况下奖金能满足
            counts.append(bonusCounts)
        else:
            g = g - bonusSum
            # 该情况下，奖金不能满足，还要去找奖金拿不到的情况
            # 只需要考虑目前单价最大的情况
            notBonusMaxIndex = max(notBonusIndexes)
            notBonusMaxIndexNum = data[notBonusMaxIndex][0]
            notBonuxMaxIndexPrice = (notBonusMaxIndex + 1) * 100
            for n in range(1, notBonusMaxIndexNum):
                g = g - notBonuxMaxIndexPrice
                bonusCounts = bonusCounts + 1
                if g <= 0:
                    break

            if g <= 0:
                counts.append(bonusCounts)
            else:
                pass
    return counts


result = calculate(D, G, DATA)

print(min(result))
