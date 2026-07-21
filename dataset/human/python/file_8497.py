import os

def main():
	k,n = map(int, input().split())
	a_list = list(map(int, input().split()))
	min_total = 1000000
	for i in range(n):
		if i == 0:
			a_total = a_list[i-1] - a_list[i]
			b_total = a_list[i] + k - a_list[i+1]	
		else:
			if i == n-1:
				a_total = k - a_list[i] + a_list[i-1]
				b_total = a_list[i] - a_list[0]
			else:
				a_total = k - a_list[i] + a_list[i-1]
				b_total = a_list[i] + k - a_list[i+1]

		if (a_total < min_total) or (b_total < min_total):
			if a_total <= b_total:
				min_total = a_total
			else:
				min_total = b_total
	print(min_total)

if __name__ == "__main__":
	main()
