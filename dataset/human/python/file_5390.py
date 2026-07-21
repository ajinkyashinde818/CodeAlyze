def main()
  n, m = gets.chomp.split.map(&:to_i)
  from_1 = []
  from_n = []
  m.times do
    keiro = gets.chomp.split.map(&:to_i)
    from_1 << keiro.last if keiro.first == 1
    from_n << keiro.first if keiro.last == n
  end
  (from_1 & from_n).first ? "POSSIBLE" : "IMPOSSIBLE"
end

puts main
