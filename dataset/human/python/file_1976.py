N, M = gets.split.map( &:to_i )

A = Array.new( N ) do gets end
B = Array.new( M ) do gets end

def match( y, x )
	M.times do |i|
		M.times do|j|
			if A[ y + i ][ x + j ] != B[i][j] then
				return false
			end
		end
	end

	return true
end

( N - M + 1 ).times do |i|
	( N - M + 1 ).times do |j|
		if match( i, j ) then
			puts "Yes"
			exit( 0 )
		end
	end
end

puts "No"
