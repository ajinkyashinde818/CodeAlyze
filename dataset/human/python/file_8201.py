def C(n,k)
  k = n - k if n - k < k 
  k.times.inject(1){|s,i| s * (n - i) / (i + 1) }
end
K, S = gets.split.map(&:to_i)
ans = (0..3).inject(0) do |t, i|
  sign = i.even? ? 1 : -1
  n = S + 3 - (K + 1) * i - 1
  n >= 2 ? t + sign * C(n, 2) * C(3, i) : t
end
puts ans
