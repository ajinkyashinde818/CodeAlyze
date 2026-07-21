def f(s)
	s =~ /(\d?m)?(\d?c)?(\d?x)?(\d?i)?/
	[$1,$2,$3,$4].map{|x| x ? g(x) : 0}.inject(:+)
end

def g(s)
	n = 0
	s =~ /(\d?)(\w)/
	c = ($1 == "" ? 1 : $1.to_i)
	x = {?m => 1000, ?c => 100, ?x => 10, ?i => 1}[$2]
	c * x
end

def h(n)
	s = ""
	k = n / 1000
	s += (k > 1 ? k.to_s : "") + "m" if k > 0
	n %= 1000
	k = n / 100
	s += (k > 1 ? k.to_s : "") + "c" if k > 0
	n %= 100
	k = n / 10
	s += (k > 1 ? k.to_s : "") + "x" if k > 0
	n %= 10
	k = n
	s += (k > 1 ? k.to_s : "") + "i" if k > 0
	s
end

n = gets.to_i
n.times {
	x, y = gets.chomp.split
	puts h(f(x) + f(y))
}
