def solve(a,b,n,m)
	ans=false
	for i in 0..n-m
		for j in 0..n-m
			same=true
			for k in 0..m-1
				for l in 0..m-1
					if a[i+k][j+l]!=b[k][l]
						same=false
					end
				end
			end
			if same==true then ans=true end
		end
	end
	puts ans==true ? "Yes" : "No" 
end

if __FILE__==$0
	rl_i=lambda{|str,dl|str.strip.split(dl).map(&:to_i)}
	r_s=lambda{|str|str.strip}
	dl=" "
	n=rl_i[gets,dl]
	a=[]
	b=[]
	n[0].times do |i|
		a.push(r_s[gets])
	end
	n[1].times do |i|
		b.push(r_s[gets])
	end
	solve(a,b,n[0],n[1])
end
