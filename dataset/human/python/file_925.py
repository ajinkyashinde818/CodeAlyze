import sys
def input():
	return sys.stdin.readline().strip()

N, C = list(map(int, input().split()))
sushi = []
for i in range(N):
	sushi.append(tuple(map(int, input().split())))

sushi_sum = [0]
for i in range(N):
	sushi_sum.append(sushi_sum[-1] + sushi[i][1])


right_max = 0
right_list = []
left_max = 0
left_list = []
for i in range(N):
	if right_max < sushi_sum[i + 1] - sushi[i][0]:
		right_max = sushi_sum[i + 1] - sushi[i][0]
	right_list.append(sushi_sum[i + 1] - sushi[i][0])
	if left_max < sushi_sum[-1] - sushi_sum[i] - (C - sushi[i][0]):
		left_max = sushi_sum[-1] - sushi_sum[i] - (C - sushi[i][0])
	left_list.append(sushi_sum[-1] - sushi_sum[i] - (C - sushi[i][0]))

for i in range(1, N):
	right_list[i] = max(right_list[i - 1], right_list[i])
for i in range(N - 2, -1, -1):
	left_list[i] = max(left_list[i + 1], left_list[i])

right_left_max = 0
for i in range(N - 1):
	right_left_max = max(right_left_max, sushi_sum[i + 1] - 2*sushi[i][0] + left_list[i + 1])

left_right_max = 0
for i in range(1, N):
	left_right_max = max(left_right_max, sushi_sum[-1] - sushi_sum[i] - 2*(C - sushi[i][0]) + right_list[i - 1])

print(max(right_max, left_max, right_left_max, left_right_max))
