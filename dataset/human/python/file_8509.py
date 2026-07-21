k, n = [0] * 2
a = []

def format_input(filename = None):
	global k, n
	global a
	if filename == None:
		k, n = list(map(int, input().split()))
		a = list(map(int, input().split()))

	elif filename == '__random__':
		from random import randint as rng
		from random import sample
		k = rng(2, 10**6)
		n = rng(2, 2 * 10**5)
		a = sample(range(k), n)
		a.sort()
		print(k, n)
		print(' '.join(list(map(str, a))))

def get_answer():
	deff_a = [a[i] - a[i-1] for i in range(1, n)]
	answer = k - max(max(deff_a), k - a[-1] + a[0])
	return answer

if __name__ == '__main__':
	format_input()

	ans = get_answer()
	print(ans)
