N=gets.to_i
S=gets.strip.codepoints
W="W".codepoints[0]
B="B".codepoints[0]

def time(n)
    out=1
    for i in 1..n
        out*=i
        out=out % (10**9+7)
    end
    out
end

ls=S.map.with_index{|e,i| i%2==0 ? (e==W ? B : W) : e}
lcnt=0
ans=1
ls.each do |e|
    if e==W
        lcnt+=1
    else
        ans*=lcnt
        lcnt-=1
    end
    ans=ans % (10**9+7)
end
ans=0 if lcnt!=0
ans=ans * time(N) % (10**9+7)
puts ans
