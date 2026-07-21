def solve(n,m,a,b)
  size = n - m
  (0..size).each do |xdiff|
    (0..size).each do |ydiff|
      if check(xdiff,ydiff,a,b,m)
        puts "Yes"
        return
      end
    end
  end
  puts "No"
end

def check(x,y,a,b,m)
  (0...m).each do |xx|
    (0...m).each do |yy|
      next if b[yy][xx] == a[y+yy][x+xx]
      return false
    end
  end
  return true
end


def main
  n, m = gets.split.map(&:to_i)
  a = []
  n.times do
    a << gets.chomp.split(//)
  end
  b = []
  m.times do
    b << gets.chomp.split(//)
  end
  solve(n,m,a,b)
end

main
