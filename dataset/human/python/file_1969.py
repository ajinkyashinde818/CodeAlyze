def create(num)
  Array.new(num){ Array.new(num) }
end

def input(array, num)
  num.times do |i|
    input = gets.chomp.split('')
    input.each_with_index do |c, j|
      array[i][j] = c
    end
  end
end

n, m = gets.chomp.split(' ').map(&:to_i)

a = create(n)
b = create(m)
input(a, n)
input(b, m)

def check(a, b, i, j)
  b.length.times do |k|
    b.length.times do |l|
      return false if a[i+k][j+l] != b[k][l]
    end
  end
  true
end

(n-m+1).times do |i|
  (n-m+1).times do |j|
    is_match = check(a, b, i, j)
    if is_match
      puts 'Yes'
      exit
    end
  end
end
puts 'No'
