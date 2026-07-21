$k, $n = gets.split.map(&:to_i)
$a = gets.split.map(&:to_i)

def distance(from_idx, to_idx)
  if from_idx < to_idx
    $a[to_idx] - $a[from_idx]
  else
    $k - $a[from_idx] + $a[to_idx]
  end
end

answer = distance(0, $n - 1)
($n - 1).times do |i|
  d = distance(i + 1, i)
  if d < answer
    answer = d
  end
end

puts answer
