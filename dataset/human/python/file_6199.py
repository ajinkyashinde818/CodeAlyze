def f(books, sw)
	d = 1
	rest = sw
	books.each do |bw|
		return Float::INFINITY if bw > sw
		if rest < bw
			d += 1
			rest = sw - bw
		else
			rest -= bw
		end
	end
	d
end

loop do
	m, n = gets.split.map &:to_i
	break if m == 0
	books = (1..n).map {gets.to_i}
	l = 0
	r = books.inject(:+)

	min = Float::INFINITY	
	loop do
		if r < l
			p min
			break
		end
		c = (l + r) / 2
		if f(books, c) <= m
			min = c
			r = c - 1
		else 
			l = c + 1
		end
	end
end
