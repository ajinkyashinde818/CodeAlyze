def min(a,b); a < b ? a : b; end
def max(a,b); a > b ? a : b; end

D, G = gets.split.map(&:to_i)
P = (1 .. D).map do |w|
  c,b = gets.split.map(&:to_i)
  [w,c,b]
end

ans = (1 << D).times.inject(1000_000) do |min_solve, complete|
  unused, used = D.times.partition{|i| complete[i].zero? }

  solved_offset = used.inject(0){|s,i| s + P[i][1]}
  next min_solve if solved_offset >= min_solve
  
  point = used.inject(0){|s, i| s + 100 * P[i][0] * P[i][1] + P[i][2] }
  next min(min_solve, solved_offset) if point >= G
  
  rest = unused.reverse_each.inject([0, G - point]) do |s, i|
    solved_count, rest = s
    w,c,b = P[i]
    r = min((rest + 100 * w - 1) / (100 * w), c - 1)
    if rest - 100 * w * r <= 0
      break [solved_count + r, 0]
    else
      [solved_count + r, rest - 100 * w * r]
    end
  end
  
  if rest[1].zero?
    min(min_solve, solved_offset + rest[0]) 
  else
    min_solve
  end
  
end

puts ans
