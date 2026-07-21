n,k = [int(e) for e in input().split(" ")[:2]]
a_ls = [int(e) for e in input().split(" ")[:n]]

a_dic = {i+1: a_ls[i] for i in range(n)}
v_f_dic = {i+1: False for i in range(n)}

pos = 1
v_ls = [pos]
v_f_dic[pos] = True
# 繰り返しの探索
for i in range(k):
	# 更新
	pos = a_dic[pos]
	v_ls.append(pos)
	if v_f_dic[pos] is True:
		# 繰り返しの長さを計算
		idx0, idx1 = [i for i,e in enumerate(v_ls) if e == pos][:2]
		rep_l = idx1 - idx0
		rep_ls = v_ls[idx0:idx1]
		ans_idx = (k-idx0)%rep_l
		print(rep_ls[ans_idx])
		import sys
		sys.exit()
	v_f_dic[pos] = True
print(pos)
