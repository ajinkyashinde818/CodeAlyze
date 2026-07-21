import numpy as np

D, G = map(int, input().split())

PC = []
ans = 10 ** 9

for _ in range(D):
    PC.append(list(map(int, input().split())))

PC = np.array(PC)

for i in range(2 ** D):
    score = 0
    count = 0

    for j in range(D):
        if (i >> j) & 1:
            score += (j+1) * 100 * PC[j,0] + PC[j,1]
            count += PC[j,0]

    if score >= G:
        ans = min(ans, count)

    if score < G:
      for k in range(D):
            sub_score = 0
            sub_count = 0

            if ~(i >> k) & 1:
                for _ in range(PC[k,0] - 1):
                    sub_score += (k+1) * 100
                    sub_count += 1
                    if sub_score >= (G - score):
                        ans = min(ans, count+sub_count)
                        break

print(ans)
