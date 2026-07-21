N, M = gets.split.map &:to_i
A = N.times.map{ gets.chomp }
B = M.times.map{ gets.chomp }

def clip(x, y)
  M.times.map{|v|
    A[y+v][x, M]
  }
end

for x in 0..(N-M)
  for y in 0..(N-M)
    if clip(x, y) == B
      puts "Yes"; exit
    end
  end
end
puts "No"
