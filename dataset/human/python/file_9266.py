DREAM = "dream"
ER = "er"
ERASE = "erase"
R = "r"

def judge(str)
  s = str
  while s.length > 0
    if s.start_with?(DREAM)
      s.slice!(0..4)
      if !s.start_with?(ERASE) && s.start_with?(ER)
        s.slice!(0..1)
      end
    elsif s.start_with?(ERASE)
      s.slice!(0..4)
      if s.start_with?(R)
        s.slice!(0)
      end
    else
      break
    end
  end
  puts s.length > 0 ? "NO" : "YES"
end

s = gets.chomp
judge(s)
