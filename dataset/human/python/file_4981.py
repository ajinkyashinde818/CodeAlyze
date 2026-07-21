MOD = 10**9+7
ONE = '1'.freeze
def inv(x)
    res = 1 # 逆元をどんどんかけるやつ
    beki = x # 逆元を計算したい値のMOD化でのべき乗
    (MOD - 2).to_s(2).reverse.chars do |digest|
        res = (beki * res) % MOD if digest == ONE
        beki = (beki * beki) % MOD
    end
    res
end

N = gets.chomp.to_i
str = gets.split
a = Array.new(N)
for i in 0...N do
    a[i] = str[i].to_i
end
b = Array.new(N-1)
b[-1] = a[-1] - a[-2]
for i in 2..N-1 do
    b[-i] = b[-i+1] + a[-i] - a[-i-1]
end

c = 1
for i in 2...N do
    c *= i
    c %= MOD
end
answer = 0
for i in 0...N-1 do
    answer += (b[i]*c*inv(i+1)+MOD)%MOD
    answer %= MOD
end
puts answer
