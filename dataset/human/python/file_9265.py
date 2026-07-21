def check(s)
  t = ['dream','dreamer','erase','eraser'].map(&:reverse)
  while s.length > 0
    if s.length >= 5 && t.include?(s.reverse[0..4])
      s = s[0..-6]
    elsif s.length >= 6 && t.include?(s.reverse[0..5])
      s = s[0..-7]
    elsif s.length >= 7 && t.include?(s.reverse[0..6])
      s = s[0..-8]
    else
      return "NO"
    end
  end
  "YES"
end

s = gets.chomp
puts check(s)
