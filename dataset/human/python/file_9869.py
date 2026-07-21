import math

def input_num():
	ls = input().strip().split(" ")
	return [int(e) for e in ls]

n,k = input_num()
a_ls = input_num()

d = {}
now = 1
result_ls = [now]
cnt = 0
while True:
	d[now] = cnt
	now = a_ls[now-1]
	if now in d:
		bun = d[now]
		break
	result_ls.append(now)
	cnt += 1


if k < bun:
	print(result_ls[k])
else:
	jun = len(result_ls) - bun
	idx = bun + (k-bun)%jun
	print(result_ls[idx])
