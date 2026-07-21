R, G, B, N = gets.chomp.split(" ").map(&:to_i)

def max_times(total, unit)
  [ total / unit, total % unit ]
end

combination_count = 0

r, mod = max_times(N, R)
combination_count += 1 if mod == 0
r.downto(0) do |r|
  next if N - R*r == 0
  g, mod = max_times(N - R*r, G)
  combination_count += 1 if mod == 0
  g.downto(0) do |g|
    next if N - R*r - G*g == 0
    b, mod = max_times(N - R*r - G*g, B)
    next combination_count += 1 if mod == 0
  end
end

puts combination_count
