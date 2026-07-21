def dp(array)
  max = 0
  for i in 1...array.size
    for j in 1...array[0].size
      array[i][j] = [array[i - 1][j - 1], array[i - 1][j], array[i][j - 1]].min + 1 if array[i][j] != 0
      max = array[i][j] if max < array[i][j]
    end
  end
  return max
end
def main
  while (n = gets.to_i) != 0
    array = Array.new(1, Array.new(n + 1, 0))
    n.times do
      array << ([0] + gets.chomp.split(//).map{|c|
        if c == "."
          1
        else
          0
        end
        })
    end
    puts dp(array)
  end
end
main
