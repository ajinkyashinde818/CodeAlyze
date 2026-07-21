def power_of_2?(n)
  (n & (n - 1)) == 0
end

def max_divisor(n)
  n & -n
end

def g(sequence)
  table = [-1] * sequence.inject(1, &:+)
  table[0] = 0

  sum = 0
  sequence.each do |x|
    (sum & -x).step(0, -x) do |a|
      b = a + x
      if table[a] >= 0 && table[b] < table[a] + 1
        table[b] = table[a] + 1
      end
    end
    sum += x
  end

  indices = []
  i = 1
  while i <= sum
    indices << i
    i <<= 1
  end
  table.values_at(*indices).max
end

def extract(sequence, k)
  subsequence = sequence.select{|x| x % k == 0 && power_of_2?(x / k)}
  min = subsequence.min
  subsequence.map{|x| x / min}
end

def f(sequence)
  numbers = sequence.map{|k| k / max_divisor(k)}.uniq
  numbers.map{|k| g(extract(sequence, k))}.max
end

loop do
  n = gets.to_i
  break if n == 0
  sequence = gets.split.map!(&:to_i)
  puts f(sequence)
end
