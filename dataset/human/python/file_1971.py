def template_match(m, x, y, a, b)
  m.times do |i|
    m.times do |j|
      return false unless a[x + i][y + j] == b[i][j]
    end
  end
  true
end

n, m = gets.split.map(&:to_i)
a = []
b = []
n.times { a << gets.split('') }
m.times { b << gets.split('') }
(0..(n - m)).each do |i|
  (0..(n - m)).each do |j|
    if template_match(m, i, j, a, b)
      puts 'Yes'
      exit
    end
  end
end
puts 'No'
