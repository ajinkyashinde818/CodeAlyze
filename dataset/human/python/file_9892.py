n, k = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i).map { |x| x - 1 }


def f(n, k, a)
  t = Array.new(a.size, -1)
  cnt = 0
  now = 0
  prev = 0
  loop do
    if t[now] == -1
      t[now] = cnt
      cnt += 1
      prev = now
      now = a[now]
      if cnt == k
        puts now + 1
        return
      end
    else
      k1 = k - t[now]
      m = cnt - t[now]
      k2 = k1 % m

      loop do
        if k2 == 0
          puts now + 1
          return
        end
        k2 -= 1
        now = a[now]
      end
    end
  end
end

f(n, k, a)
