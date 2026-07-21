k,n = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)

def calc_distance(houses, start_point=nil, end_point=nil)
  return (houses[-1] - houses[0]) if start_point.nil?

  houses[(start_point - 1)] + end_point - houses[start_point]
end

distances = a.slice(0, a.length - 1).map.with_index { |e, i| a[(i+1)] - e }
start_point = distances.index(distances.max) + 1

puts  [calc_distance(a, start_point, k), calc_distance(a)].min
