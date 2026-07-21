def prime_division(n)
  ret = Array({Int32|Int64, Int32|Int64}).new
  return ret if n == 1

  2.upto(Math.sqrt(n).to_i) do |p|
    next if n % p != 0

    exp = 0
    while n % p == 0
      n //= p
      exp += 1
    end

    ret << {p, exp}
  end

  ret << {n, 1} if n != 1
  ret
end

n = gets.to_s.to_i64
count = 0

prime_division(n).each do |(p, e)|
  i = 1
  tmp = 2

  while i <= e
    i += tmp
    tmp += 1
    count += 1
  end
end

puts count
