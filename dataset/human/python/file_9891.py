n, k = gets.chomp.split(" ").map {|n| n.to_i}
gra = gets.chomp.split(" ").map {|n| n.to_i - 1}

def go_t(g, pos, cont, c, visi)
  if visi[pos]
    return cont - c[pos], c[pos], pos
  end
  visi[pos] = true
  c[pos] = cont
  go_t(g, g[pos], cont + 1, c, visi)
end

def final(g, pos, j)
  if (j == 0)
    return pos
  end
  final(g, g[pos], j - 1)
end

b, aux, ini = go_t(gra, 0, 0, {}, [false] * n)
if k < aux
  puts final(gra, 0, k) + 1
else
  k -= aux
  j = k % b
  puts final(gra, ini, j) + 1
end
