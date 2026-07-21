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

require "prime"

n = input_n

if Prime.prime?(n)
  puts 1
  exit
end

if n == 1
  puts 0
  exit
end

cnt = 0
# 素因数分解
div = Prime.prime_division(n)

# 素数a, 素数の個数b
# 素数をいくつ使えるか(zとして表現可能か)数える
# ex. a = 2, b = 3 のとき、2^1 = 2と2^2 = 4 でcnt += 2
# ex. a = 2, b = 4 のとき、2^1 = 2と2^2 = 4 でcnt += 2
# ex. a = 2, b = 5 のとき、2^1 = 2と2^2 = 4 でcnt += 2
# ex. a = 2, b = 6 のとき、2^1 = 2と2^2 = 4と2^3 = 8 でcnt += 3
div.each do |a, b|
  100.times do |i|
    # cntにいくつ足すかを求めるループ
    # b を 1,2,3,...で減算するとaの乗数(上のexでいう2^x)で減算するのと同じ
    # 減算した回数が個数になるので、cntにループ回数であるiを足せばzを足したのと同義
    # ※bが負になるまで計算しているため、一回多く減算しているので-1が必要な点に注意)
    #   例えばb=5の場合、i=1,2,3...の3でb<0になる
    b -= i
    if b < 0
      cnt += i - 1
      break
    end
  end
end
puts cnt
