require 'prime'
def isPrime(n)
    f = n.prime_division
    f.length == 1 && f[0][1] == 1
end
N = gets.to_i
if N == 1 then
    puts 0
    exit
end
if isPrime(N) then
    puts 1
    exit
end
factors = N.prime_division
res = 0
factors.each do |f|
    a = []
    s = 1
    b = f[1]
    loop do
        if !a.include?(s) then
            a.push s
            s += 1
            b = b - s
            break if b <= 0
            next
        else
            break
        end
    end
    res += a.length
end
puts res
