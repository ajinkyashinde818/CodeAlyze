def solve_max_square(arr, sz)
  maxWidth = 0
  w = Array.new(sz){Array.new(sz){-1}}
  sz.times{|i|
    w[i][0] = (arr[i][0] == "." ? 1 : 0)
    w[0][i] = (arr[0][i] == "." ? 1 : 0)
  }
  sz.times{|i|
    sz.times{|j|
      next if arr[i][j] == "*"
      if w[i-1][j-1] > -1 && w[i][j-1] > -1 && w[i-1][j] > -1 then
        w[i][j] = [w[i-1][j-1], w[i][j-1], w[i-1][j]].min + 1
        maxWidth = maxWidth > w[i][j] ? maxWidth : w[i][j]
      else
        w[i][j] = 1
      end
    }
  }
  return maxWidth
end

while n = gets.to_i
  break if n == 0
  arr = []
  n.times{|i|
    arr[i] = gets.chomp.split("")
  }
  p solve_max_square(arr,n)
end
