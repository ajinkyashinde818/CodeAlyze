MOD=10**9+7
cnt=0; sum=0; prev=nil; can=true; h=Hash.new(0)
def gs() gets.chomp end
def gi() gets.to_i end
def gsmi() gets.chomp.split.map(&:to_i) end

def desc(ar) ar.sort!{|x,y|y<=>x} end
def min(a,b) a<=b ? a : b end
def max(a,b) a>=b ? a : b end
def sum(ar) ar.inject(:+) end

def C(a,b) b==0||a==b ? 1 : (b=a-b if a/2<b;(a-b+1..a).inject(:*)/(1..b).inject(:*)) end

def puts_yesno(can) puts(can ? 'Yes' : 'No') end
def putsend(s) puts s; exit end
def debug(k,v) puts "#{k}:#{v}" end
########### ( ˘ω˘ )ｽﾔｧ… ###########
n=gi

putsend 0 if n%2==1

l=n.to_s.length
cnt=0

# 1.upto(l) do |i|
#   d = n/(10**i)
#   cnt+=d
# end

#50の倍数
num=10
c5=0
while num<n do
  c5+=1
  num*=5
end

1.upto(c5) do |i|
  d = n/((5**i)*10)
  #puts d
  cnt+=d
end

puts cnt + n/10
