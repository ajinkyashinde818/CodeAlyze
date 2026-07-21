s = gets.chomp

def judge(s)
    s = s.chomp("dream")
    s = s.chomp("dreamer")
    s = s.chomp("erase")
    s = s.chomp("eraser")
    s
end

while true
    t = judge(s)
    if t == s
        puts "NO"
        break
    elsif t == ''
        puts "YES"
        break
    end
    s = t
end
