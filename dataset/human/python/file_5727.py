s = gets.chomp
t = s.gsub(/x/, "")

def kaibun(s)
  n = s.size
  (n / 2).times do |i|
    return false if s[i] != s[n - 1 - i]
  end
  true
end

def xnum(s, t)
  a = Array.new(t.size + 1, 0)
  i = 0
  s.chars.each_with_object(a) do |c|
    if c == "x"
      a[i] += 1
    else
      i += 1
    end
  end
end

def xcount(a)
  n = a.size
  ans = 0
  (n / 2).times do |i|
    ans += (a[i] - a[n - 1 - i]).abs
  end
  ans
end

def calc(s, t)
  return -1 if !kaibun(t)
  xcount(xnum(s, t))
end

puts calc(s, t)
