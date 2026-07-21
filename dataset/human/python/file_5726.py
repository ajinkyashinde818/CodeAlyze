def is_palindrome(s)
  (s.size / 2).times do |i|
    return false if s[i] != s[(s.size - 1) - i]
  end

  return true
end

def main(argv)
  s = gets.chomp

  t = ''
  s.size.times{ |i| t += s[i] if s[i] != 'x' }

  unless is_palindrome(t) then
    puts (-1).to_s
    return
  end

  if t.size == 0 then
    puts 0.to_s
    return
  end

  m = t.size / 2
  m += 1 if t.size % 2 == 1

  c = 0
  k1 = -1
  0.upto(s.size - 1).each do |i|
    if s[i] != 'x' then
      c += 1
      k1 = i
      break if c == m
    end
  end

  c = 0
  k2 = -1
  (s.size - 1).downto(0).each do |i|
    if s[i] != 'x' then
      c += 1
      k2 = i
      break if c == m
    end
  end

  v = [0]
  0.upto(k1).each do |i|
    if s[i] != 'x' then
      v.push(0)
    else
      v[v.size - 1] += 1
    end
  end

  u = [0]
  (s.size - 1).downto(k2).each do |i|
    if s[i] != 'x' then
      u.push(0)
    else
      u[u.size - 1] += 1
    end
  end

  s = 0
  v.size.times do |i|
    s += (v[i] - u[i]).abs
  end
  puts s.to_s
end

if self.to_s == 'main' then
  main(ARGV)
end
