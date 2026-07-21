N, C = gets.split.map(&:to_i)
xs = []
vs = []
N.times do 
  x, v = gets.split.map(&:to_i)
  xs << x
  vs << v
end
X = xs
V = vs

def solve(xs, vs)
  xs = [0] + xs
  vs = [0] + vs

  right_col = [0]
  left_col = [0]
  for i in 1..N
    col = right_col[i-1] - (xs[i]-xs[i-1]) + vs[i]
    right_col << col

    d = xs[-i+1]
    if d==0
      d = C
    end

    col = left_col[i-1] - (d-xs[-i]) + vs[-i]
    left_col << col
  end

  left_col_max = []
  left_col_max[N+1] = 0
  for r in (1..N).to_a.reverse
    left_col_max[r] = [left_col_max[r+1], left_col[N-r]].max
  end

  max_sushi = 0
  max_sushi = [max_sushi, right_col.max].max

  for r in 1..N
    w = right_col[r] - xs[r] + left_col_max[r]
    max_sushi = [max_sushi, w].max
  end

  max_sushi
end

puts [solve(xs, vs), solve(xs.reverse.map {|x| C-x}, vs.reverse)].max
