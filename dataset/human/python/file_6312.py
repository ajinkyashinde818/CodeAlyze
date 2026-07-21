def min(a, b)
  a < b ? a : b
end

n = gets.chomp.split("").map(&:to_i).reverse
n << 0
n_size = n.size

dp = Array.new(n_size+1){Array.new(2, 0)}
dp[0][1] = 1
n_size.times do |i|
  num = n[i]
  dp[i+1][0] = min(num + dp[i][0], num + 1 + dp[i][1])
  dp[i+1][1] = min(10 - num + dp[i][0], 10 - (num + 1) + dp[i][1])
end
p dp.last[0]
