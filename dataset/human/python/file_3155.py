import math
n = int(input())

res = 0
if n <= 1:
	print(res)
else:
	max_num = math.ceil(math.sqrt(n + 1))
	org_n = n
	target_list = []
	for z in range(2, max_num + 1):
		if n % z == 0:
			z_p = 1
			z_count = 0
			while n % z == 0:
				z_p *= z
				n = n // z
				if z_p not in target_list:
					target_list.append(z_p)
					z_p = 1
		if n == z:
			break
	res = len(target_list)
	if n > max_num and n not in target_list:
		res += 1

	print(res)
