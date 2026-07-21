def pow(x,n)
  if n == 0
    ""
  elsif n % 2 == 0
    pow((x+x), n/2)
  else
    x + pow(x, n-1)
  end
end


n,k,s = gets.chomp.split(" ").map(&:to_i);

ans = ""
if s > 1000000

  ans = pow("#{s} ",k) + pow("#{1} ",n-k)

else

  ans = pow("#{s} ",k) + pow("#{s+1} ",n-k)

end

print ans
