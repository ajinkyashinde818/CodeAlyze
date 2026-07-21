def count_take(val)
    current = 1
    count = 0
    while val >= current
        val -=current
        current += 1
        count += 1
    end
    count
end

require 'prime'
n = gets.to_i
if n == 1
    puts 0
    exit
end

puts Prime.prime_division(n).map{|it| it[1]}.map{|it|
    count_take(it)
}.inject(:+)
