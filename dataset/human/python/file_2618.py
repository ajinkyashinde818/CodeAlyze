import itertools

D,G = map(int, input().split())
PC = [list(map(int, input().split())) for _ in range(D)]

P_list = list(range(D))
cnt = float('inf')

for i in range(D):
	for bonus in itertools.combinations(P_list, i):

		tmp_cnt = 0
		score = 0

		for j in bonus:
			score += PC[j][0] * 100 * (j+1) + PC[j][1]
			tmp_cnt += PC[j][0]

		res_max_p = max([k for k in range(D) if k not in bonus])
		res_score = G - score
		if res_score > 0:
			t = (-res_score//((res_max_p+1)*100)) * (-1) 
			if t < PC[res_max_p][0]:
				tmp_cnt += t
			else:
				continue

		cnt = min(cnt, tmp_cnt)

if cnt == float('inf'):
	cnt = sum([PC[j][0] for j in range(D)])

print(cnt)
