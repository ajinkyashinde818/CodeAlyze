def calc(a, b, c)
  if a + b == c then
    return (2 * b) + a
  elsif a + b < c then
    return (2 * b) + (a + 1)
  else # a + b > c
    return b + c
  end
end

def main(argv)
  (a, b, c) = gets.chomp.split(' ').map(&:to_i)
  
  puts calc(a, b, c).to_s
end

if self.to_s == 'main' then
  main(ARGV)
end
