d,g = read_line.split.map(&.to_i)
p = [-1] of Int32
c = [-1] of Int32

(1..d).each do |_|
	a,b = read_line.split.map(&.to_i)
	p << a
	c << b
end

ans = (0...(1<<d)).min_of do |pat|
	res = 0
	k = 0
	
	a,b = d.downto(1).partition { |i| flag?(pat,i) }
	
	a.each do |i|
		res += 100*i*p[i]+c[i]
		k += p[i]
	end

	b.each do |i|
		if res < g
		  x = [ceil_div(g-res,100*i),p[i]].min
		  res += 100*i*x
		  k += x
		end
	end

	res >= g ? k : 10000
end

puts ans

##
def ceil_div(a,b)
	a / b + (a%b>0?1:0)
end

def flag?(pat,i)
	(pat>>(i-1)) & 1 == 1
end
