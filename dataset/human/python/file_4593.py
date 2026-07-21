require 'prime'

n = gets.chomp.to_i

if n == 1
  puts 0
  exit
end

prime_division = Prime.prime_division(n)
powers = prime_division.map(&:last).sort

def initialize_hash(powers)
  h = {}

  max = powers.last
  n = 1
  sum = 0
  while sum < max
    sum = n * (n + 1) / 2
    h[n] = sum
    n += 1
  end

  h
end

h = initialize_hash(powers)
h_values = h.values.sort.reverse

def calc_h(h, h_values, power)
  return h.key(power) if h.has_value?(power)

  greatest_value_less_than_power = h_values.find { |x| x < power }
  raise unless greatest_value_less_than_power

  h.key(greatest_value_less_than_power)
end

results = powers.map { |power| calc_h(h, h_values, power) }

puts results.sum
