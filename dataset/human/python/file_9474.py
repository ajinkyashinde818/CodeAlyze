from collections import defaultdict

N,K = map(int,input().split())
A = list(map(int,input().split()))
position = 1
past_path = defaultdict(lambda : -1)
loop_pos = -1

def move(position):
	return A[position-1]

for i in range(1,K+1):
	if(past_path[position] != -1):
		loop_pos = past_path[position]
		break
	past_path[position] = i-1
	position = move(position)

new_past_path = defaultdict(lambda : -1)
for k,v in past_path.items():
	if v >= loop_pos:
		new_past_path[v-loop_pos] = k

if loop_pos != -1:
	print(new_past_path[(K-loop_pos)%len(new_past_path)])
else:
	print(position)
