MOD = 1000000007i64
n = read_line.to_i
x = read_line.split.map(&.to_i)
d = Array.new(n - 1) { |i| x[i + 1] - x[i] }
fact = Array.new(n, 1i64)
(n - 1).times do |i|
  fact[0] *= (i + 1)
  fact[0] %= MOD
end
1.upto(n - 1) do |i|
  fact[i] = fact[0] * inv(i.to_i64) % MOD
end
2.upto(n - 1) do |i|
  fact[i] = (fact[i] + fact[i - 1]) % MOD
end
ans = 0i64
(n - 1).times do |i|
  ans += fact[i + 1] * d[i]
  ans %= MOD
end
puts ans

def inv(v)
  pow(v, MOD - 2)
end

def pow(v, p)
  return 1i64 if p == 0
  return v if p == 1
  ret = pow(v, p >> 1)
  ret *= ret
  ret %= MOD
  if p % 2 == 1
    ret *= v
    ret %= MOD
  end
  ret
end
