def countwhen(n, a, b)
  count = 0
  (n / a + 1).times do |i|
    count += 1 if (n - i * a) % b == 0
  end
  return count
end

r, g, b, n = gets.chomp.split.map(&:to_i)
count = 0
(n / r + 1).times do |i|
  count += countwhen(n - i * r, g, b)
end

puts count
