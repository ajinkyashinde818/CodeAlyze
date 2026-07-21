def input_n
  gets.to_i               # 単一整数
end

def input_s
  gets.chomp              # 文字列。chompを付けないと改行文字がついてくる
end

def input_a
  gets.split.map(&:to_i)  # スペースで区切られた複数の整数
end

def input_o(num)
  num.times.map { gets.to_i }  # 縦に並んだ複数の整数。たまにある
end

def output_f(num)
  puts sprintf("%.12f", num)
end

n, k = input_a
a = input_a
b = Array.new(n, -1)
index = 0
cnt = 0
while cnt < k
  if b[index] != -1
    nokori = k - cnt
    amari = nokori % (cnt - b[index])
    amari.times do |i|
      index = a[index] - 1
    end
    puts index + 1
    exit
  end
  b[index] = cnt
  index = a[index] - 1
  cnt += 1
end
puts index + 1
