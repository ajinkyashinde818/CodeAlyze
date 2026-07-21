require 'prime'

def max(a,b); a > b ? a : b; end
dp = Array.new(41, -1); dp[0] = 0
(1 .. 40).each do |a|
  40.downto(1) do |sum|
    dp[sum] = max(dp[sum], dp[sum - a] + 1) if dp[sum - a] >= 0 && sum - a >= 0
  end
end
N = gets.to_i
ans = N.prime_division.inject(0) do |s, (n,e)|
  s + dp[e]
end
puts ans
