n, m = gets.strip.split.map(&:to_i)
a = n.times.map{ gets.strip.split("") }
b = m.times.map{ gets.strip.split("") }

def foo(bar, baz, m, b, a)
    hoge = 0
    m.times do |i|
        b[0].length.times do |j|
            hoge = 1 if a[bar + i][baz + j] != b[i][j]
            break if hoge == 1
        end
        break if hoge == 1
    end
    return hoge
end

fuga = 0
(n - m + 1).times do |i|
    (a[0].length - b[0].length + 1).times do |j|
        fuga = 1 if foo(i, j, m, b, a) == 0
        break if fuga == 1
    end
    break if fuga == 1
end

puts fuga == 1 ? "Yes" : "No"
