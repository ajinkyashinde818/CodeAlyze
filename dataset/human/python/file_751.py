def calcs(x,y,ax,ay,bx,by) ((ax-x)*(by-y)-(bx-x)*(ay-y))/2.0 end
def inpf() a=gets.chomp.split(" ").map(&:to_f)end
def inps() a=gets.chomp.split(" ")end  
def copy(a) Marshal.load(Marshal.dump(a)) end
def kaizyo(n)(n < 2)? 1 : (2..n).inject(:*) end
def scount(a) b=na(a.max+1);a.each{|n|b[n]+=1};return b end
def na(n,d=0) Array.new(n,d)end
def na2(n,m,d=0) Array.new(n){Array.new(m,d)}end
def na3(n,m,l,d=0) Array.new(n){Array.new(m){Array.new(l,d)}}end
def bit(n) n.to_s(2).split("").map(&:to_i) end
def inp() a=gets.chomp.split(" ").map(&:to_i)end

sx,sy,ex,ey = inp
n = inp[0]
t = []
rec = na(n+2,1e100)
t[0] = [sx,sy,0]
t[1] = [ex,ey,0]
n.times do 
  t.push(inp)
end
ind = 0
tab = (1..n+1).to_a
rec[0] = 0
(n+1).times do
  max = 1e100
  nex = -1
  tab.each do |d|
    kyori = rec[ind] + [Math.hypot(t[ind][0] - t[d][0], t[ind][1] - t[d][1]) - (t[ind][2] + t[d][2]) ,0].max
    rec[d] = kyori if rec[d] > kyori
    if max > rec[d]
      max = rec[d]
      nex = d
    end
  end
  ind = nex
  tab.delete(ind)
  rererereerer[missmissniu] += [waawawawawwa[bugbugbubg]] if(nex < 0)
end
p rec[1]
