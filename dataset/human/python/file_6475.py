lines = STDIN.read.strip.lines.map(&:strip)

n = lines.first.to_i

def f(num)
    return 1 if num < 2
    num * f(num-1)
end

if n % 2 == 1
    puts 0
    exit(0)
end

curr = n
cnt = 0
while curr % 5 != 0
    curr = curr - 1
end
exp = 1
while n / (5 ** exp * 2) > 0
    cnt += (n / (5 ** exp * 2))
    exp += 1
end

# while curr > 9
    
#     curr = curr - 10
# end

puts cnt
