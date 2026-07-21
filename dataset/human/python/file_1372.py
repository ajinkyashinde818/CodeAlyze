def splitting_pile_2():
	n = int(raw_input())
	nums = list(map(int, raw_input().split(" ")))
	total_sum = sum(nums)
	left_sum = nums[0]
	ans = abs(total_sum-left_sum*2)

	for i in range(1, n-1):
		left_sum = left_sum + nums[i]
		ans = min(ans, abs(total_sum-left_sum*2))
	print ans


if __name__ == "__main__":
	splitting_pile_2()
