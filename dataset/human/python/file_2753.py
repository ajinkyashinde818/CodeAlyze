def aa(n)
    a = []
    0.upto(10) do |i|
        a << i if n & 2**i == 2**i
    end
    a
end

d,g = gets.chomp.split.map(&:to_i)
p = []
c = []
pc = []
d.times do |i|
    pp,cc = gets.chomp.split.map(&:to_i)
    p << pp
    c << cc
    pc << (i+1) * 100 * pp + cc
end

ans = 0
0.upto(2**d-1) do |i|
    t = aa(i)
    tt = ((0..(d-1)).to_a - t)[-1]
    score = 0
    prob = 0
    t.each do |j|
        score += pc[j]
        prob += p[j]
    end
    if g <= score
        ans = prob if ans == 0 || ans > prob
    elsif g <= score + p[tt] * 100 * (tt+1)
        prob += ((g - score - 1) / (100 * (tt+1)) + 1)
        ans = prob if ans == 0 || ans > prob
    end
end
puts ans
