def geq(ga, gb, m, bi, bj)
  (0...m).each do |i|
    (0...m).each do |j|
      if (ga[bi+i][bj+j] != gb[i][j])
        return false
      end
    end
  end
  return true
end

def solve
  n,m = gets.scan(/-?[\d\.]+/).map(&:to_i)
  a = Array.new(n)
  b = Array.new(m)
  n.times do |i|
    a[i] = gets
  end
  m.times do |i|
    b[i] = gets
  end

  (0..(n-m)).each do |bi|
    (0..(n-m)).each do |bj|
      if geq(a, b, m, bi, bj)
        puts "Yes"
        return
      end
    end
  end

  puts "No"
end

solve
