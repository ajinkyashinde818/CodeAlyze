def solve_el(from, to, max, set)
  return true if from == to
  return false if from < to

  set.each do |i|
    next if i > from
    return true if solve_el(from % i, to, max, set)
  end

  max.downto(1).each do |i|
    next if i > from
    return true if solve_el(from % i, to, max, set)
  end

  return false
end

def solve_part(from, to, max, set)
  from.length.times do |i|
    return false if !solve_el(from[i], to[i], max, set)
  end
end

length = gets.chomp.to_i
from = gets.split.map(&:to_i)
to = gets.split.map(&:to_i)

if solve_part(from, to, 50, [])
  res = []

  50.downto(1) do |i|
    if !solve_part(from, to, i - 1, res)
      res.push(i)
    end
  end

  puts res.map{|i|2**i}.reduce(&:+) || 0
else
  puts -1
end
