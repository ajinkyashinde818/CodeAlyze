def prime_factor(n)
  prime = []
  2.upto(n) do |i|
    break unless i <= n / i
    while (n % i).zero?
      prime << i
      n /= i
    end
  end
  prime << n unless n == 1
  prime
end

h=Hash.new{|h,k|h[k]=0}
prime_factor(gets.to_i).each do |i| h[i]+=1 end
ans=0
h.each do |_,v|
  1.upto(v) do |i|
    v-=i
    break if v<0
    ans+=1
  end
end
p ans
