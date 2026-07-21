require 'set'
def score(n, a, c)
    reached = Set.new
    s = 0
    (0..n-1).each do |i|
        (0..i).each do |j|
            g = a[i][j]
            next if g == 0
            pos = [i, j]
            next if reached.include?(pos)
            dead = true
            k = 1

            stack = [pos]
            test = [pos]
            reached << pos
            until stack.empty?
                y, x = stack.pop
                [-1, 0, 1].repeated_permutation(2) do |dy, dx|
                    next if dy + dx == 0
                    y2, x2 = y + dy, x + dx
                    next if y2 < 0 || y2 > n-1 || x2 < 0 || x2 > y2
                    dead = false if a[y2][x2] == 0
                    next if a[y2][x2] != g
                    pos = [y2, x2]
                    next if reached.include?(pos)
                    stack << pos
                    reached << pos
                    k += 1
                    test << pos
                end
            end

            if dead
                s += (g == c ? -k : k)
            end
        end
    end
    s
end

loop do
    n, c = gets.split.map(&:to_i)
    break if n == 0

    a = (1..n).map { gets.split.map(&:to_i) }
    max = -Float::INFINITY

    (0..n-1).each do |i|
        (0..i).each do |j|
            next if a[i][j] != 0
            a[i][j] = c
            s = score(n, a, c)
            a[i][j] = 0
            max = s if s > max
        end
    end

    p max
end
