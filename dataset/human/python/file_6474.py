def fn(n)
  res = 1
  n.step(1, -2) do |i|
    break if n < 2
    res *= i
  end
  res
end

def count_r(n)
  rev = n.to_s.reverse
  res = 0
  rev.chars.each { |i| break if i != '0'; res += 1 }
  res
end

n = gets.to_i
if n.odd?
  puts "0"
  exit
end

# prepared_res = count_r(fn(n))
res = 0
res += n / 10
n /= 10
while n >= 5
  res += n / 5
  n /= 5
end
# res += n / 250
puts res
# puts prepared_res
# puts count_r  fn(10)
# puts count_r  fn(20)
# puts count_r  fn(30)
# puts count_r  fn(40)
# puts count_r  fn(50)
# puts count_r  fn(80)
# puts count_r  fn(96)
# puts count_r  fn(100)
# puts count_r  fn(110)
# puts count_r  fn(140)
# puts count_r  fn(150)
