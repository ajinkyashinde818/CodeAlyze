from itertools import permutations

D,G = [int(i) for i in input().split()]
L = [[int(i) for i in input().split()] for _ in range(D)]

ans = []
for i in range(2**D):
    tmp = 0
    index = 0
    index_li = []
    ans_tmp = 0
    for j in range(D):
        if (i >> j) & 1:
            tmp += L[j][0]*100*(j+1)+L[j][1]
            ans_tmp += L[j][0]
        else:
            index_li.append(j+1)
    if G >= tmp:
        for index in index_li[::-1]:
            p = 0
            while G > tmp:
                if p > L[index-1][0]:
                    break
                p += 1
                ans_tmp += 1
                tmp += index*100

    ans.append(ans_tmp)

print(min(ans))
