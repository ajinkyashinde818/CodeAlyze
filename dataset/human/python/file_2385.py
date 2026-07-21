D, G = map(int, input().split())
pc = [list(map(int, input().split())) for i in range(D)]

ans_cnt = 10 ** 20
for i in range(2 ** (D)):
    def make_p(i):
        p = bin(i)[2::]
        while len(p) != D:
            p = "0" + p
        key = D
        for j in range(D - 1, -1, -1):
            if int(p[j]) == 0:
                key = j
                break
        return p, key
    
    p_and_key = make_p(i)
    p = p_and_key[0]
    key = p_and_key[1]
    cnt = 0
    ansP = 0
    for j in range(len(p)):
        if p[j] == "1":
            ansP += pc[j][0] * 100 * (j + 1) + pc[j][1]
            cnt += pc[j][0]
    j = 0
    if int(key) != int(D):
        key = int(key)
        while ansP < G:
            j = int(j)
            if pc[key][0] <= j:
                break
            ansP += 100 * (key + 1)
            cnt += 1
            j += 1
    if ansP >= G:
        ans_cnt = min(ans_cnt, cnt)

print(ans_cnt)
