def main(argv)
  n = gets.chomp.to_i
  a = gets.chomp.split(' ').map(&:to_i)
  b = gets.chomp.split(' ').map(&:to_i)
  c = gets.chomp.split(' ').map(&:to_i)
  
  s = 0
  
  n.times do |i|
    s += b[a[i] - 1]
  end
  
  (n - 1).times do |i|
    if a[i] + 1 == a[i + 1] then
      s += c[a[i] - 1]
    end
  end
  
  puts s.to_s
end

if self.to_s == 'main' then
  main(ARGV)
end
