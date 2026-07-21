def main(str)
  kn, as = str.split("\n")
  k, _n = kn.split(" ").map(&:to_i)
  as = as.split(" ").map(&:to_i)
  as << as[0] + k
  max_diff = (0...(as.length - 1)).map { |i| as[i + 1] - as[i] }.max
  k - max_diff
end

puts main($stdin.read.chomp)
