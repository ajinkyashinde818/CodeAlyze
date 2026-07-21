def get_min_score(flags):
    score = 0
    num_probs = 0
    for j, flag in enumerate(flags):
        if flag == '1':
            score += PC[j][1] + PC[j][0] * (j + 1) * 100
            num_probs += PC[j][0]
            if score >= G:
                return num_probs

    for j in range(len(flags) - 1, -1, -1):
        if flags[j] == '0':
            for k in range(PC[j][0]):
                score += (j + 1) * 100
                num_probs += 1
                if score >= G:
                    return num_probs
    return float('inf')


D, G = map(int, input().split())
PC = [list(map(int, input().split())) for _ in range(D)]
ans = float('inf')
for i in range(2 ** D):
    flags = bin(i)[2:].zfill(D)
    ans = min(ans, get_min_score(flags))
print(ans)
