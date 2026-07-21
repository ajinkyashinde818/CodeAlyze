from collections import defaultdict

n, k = [0] * 2
a = []

def format_input(filename = None):
	global n, k
	global a
	if filename == None:
		n, k = list(map(int, input().split()))
		a = list(map(int, input().split()))

	elif filename == '__random__':
		from random import randint as rng
		n = rng(2, 2 * 10**5)
		k = rng(1, 10**18)
		a = [rng(1, n) for i in range(n)]
		print(n, k)
		print(' '.join(list(map(str, a))))

def get_answer():
	loop = [1]
	loop_index = defaultdict(int)
	start = -1
	while start == -1 and len(loop) < k + 1:
		node = a[loop[-1]-1]
		if loop_index[node] > 0:
			start = loop_index[node]
		elif node == 1:
			start = 0
		else:
			loop.append(node)
			loop_index[node] = len(loop) - 1

	l = len(loop)
	if k >= l:
		answer = loop[(k - l) % (l - start) + start]
	else:
		answer = loop[k]

	return answer

if __name__ == '__main__':
	format_input()

	ans = get_answer()
	print(ans)
