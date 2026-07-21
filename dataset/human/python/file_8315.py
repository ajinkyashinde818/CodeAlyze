def solve(n,list)
  total = 0
  list.each do |e|
    total += e
  end

  os = (n * (n + 1) / 2)
  return "NO" if total % os != 0

  count = total / os
  hand = 0

  (0...n).each do |idx|
    ni = idx + 1
    ni = 0 if ni == n
    diff = list[ni] - list[idx]
    return "NO" if (count - diff) % n != 0
    hand_diff = ((count - diff) / n)
    return "NO" if hand_diff < 0
    hand += hand_diff
  end
  if hand == count
    return "YES"
  else
    return "NO"
  end
end

def main
  n = gets.to_i
  list = gets.split.map {|e| e.to_i}
  puts solve(n,list)
end

main
