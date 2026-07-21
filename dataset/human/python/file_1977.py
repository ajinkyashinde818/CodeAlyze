io = STDIN
n,m=io.gets.chomp.split.map(&:to_i)
a,b=[],[]
n.times do
  a<<io.gets.chomp.split(//)
end
m.times do
  b<<io.gets.chomp.split(//)
end
def check2(i,j,m,a,b)
  (m).times do |x|
    (m).times do |y|
       return false unless a[x+i][y+j]==b[x][y]
    end
  end
  true
end
def check(n,m,a,b)
  (n-m+1).times do |i|
    (n-m+1).times do |j|
      return 'Yes' if check2(i,j,m,a,b)
    end
  end
  return 'No'
end
puts check(n,m,a,b)
