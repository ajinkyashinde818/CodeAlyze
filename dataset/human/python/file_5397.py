def check(s, n, x, y)
	if x == 1
		return s[0] == 'Y' if y == 0
		return s[2*n] == 'Y' if y == 1
	elsif x == n + 1
		return s[2*n-1] == 'Y' if y == 0
		return s[4*n-1] == 'Y' if y == 1
	else
		a, b = 2*x - 2, 2*x - 1
		a += 2*n if y == 1
		b += 2*n if y == 1
		return s[a-1] == 'Y' || s[b-1] == 'Y'
	end
end

def calc(n, s)
	cnt0, cnt1 = 0, 0
	lst0, lst1 = -1, -1
	fst0, fst1 = n+2, n+2
	for i in (1..n+1) do 
		cnt0, lst0, fst0 = cnt0+1, i, [fst0, i].min if check(s, n, i, 0)
		cnt1, lst1, fst1 = cnt1+1, i, [fst1, i].min if check(s, n, i, 1)
	end
	# p [cnt0, cnt1, fst0, fst1, lst0, lst1]
	return n + cnt0 + cnt1 if cnt1 == 0
	ans = n + cnt0 + cnt1 + 2
	if cnt0 != 0
		ans -= 1 if fst0 <= fst1
		ans -= 1 if lst0 >= lst1
	end
	return ans
end

gets.to_i.times do
	n = gets.to_i
	s = gets
	puts calc(n, s)
end
