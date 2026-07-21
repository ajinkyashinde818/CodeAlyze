$debug = false

def diff( box, cust )
	sum = 0
	0.upto( 8 - 1 ){|i|
		if( cust[ i ] >= box[ i ] )
			n = box[ i ]
		else 
			n = cust[ i ]
		end
		sum += (cust[ i ] - n)
	}
	return sum
end

def to_num( b )
	 b.inject{ |sum,item| sum * 10 + item }
end


answers = Array.new
box = [4,1,4,1,2,1,2,1]

while line = $stdin.gets
	cust = line.chomp.split( /\s/ ).map{ |e| e.to_i }

	b = box
	min_num = diff( b, cust )
	min_pat  = to_num( b )
	min_pat2 = b.dup

	1.upto( 7 ){
		b << b.shift
		left = diff( b, cust )

		if left < min_num
			min_num  = left
			min_pat  = to_num( b )
			min_pat2 = b.dup
		elsif left == min_num
			temp_pat = to_num(b)
			if temp_pat < min_pat
				min_pat  = temp_pat
				min_pat2 = b.dup
			end
		end
	}
	p min_pat2 if $debug
	answers << min_pat2
end

answers.each{ |a|
	a.each_with_index{ |e,i|
		print "#{e}" 
		print " " if i < 7 
	}
	puts
}
