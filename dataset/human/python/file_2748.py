def chmin(a, b) a < b ? a : b end

D, G = gets.strip.split.map(&:to_i)

counts = []
points = []
D.times { |i| counts[i], points[i] = gets.strip.split.map(&:to_i) }

res = 10 ** 6
(1<<D).times do |mask|
  sum = 0
  count = 0
  D.times do |i|
    unless (mask & (1<<i)).zero?
      sum += (counts[i] * (i + 1) * 100) + points[i]
      count += counts[i]
    end
  end

  if sum < G
    (D - 1).downto(0) do |i|
      next unless (mask & (1<<i)).zero?
      (0...counts[i]).each do
        break if sum >= G
        sum += (i + 1) * 100
        count += 1
      end
    end
  end
  res = chmin(count, res)
end

puts res
