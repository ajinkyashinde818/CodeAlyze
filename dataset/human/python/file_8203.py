def solve(k, s)
  count = 0
  nums = (0..k).to_a.sort.reverse
  nums.each do |i|
    if i <= s
      nums.each do |j|
        count += 1 if i + j <= s && s - i - j <= k
      end
    end
  end
  count
end

k, s = gets.strip.split.map(&:to_i)
puts solve(k, s)
