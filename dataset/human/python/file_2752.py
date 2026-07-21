io = STDIN
d,G=io.gets.split.map(&:to_i)
ar=d.times.map do |i|
  q,c = io.gets.split.map(&:to_i)
  [100*(i+1),q,100*(i+1)*q+c] #点数、問題数、合計
end
$ans=1000
def dfs(questions,highest,amt,num)
  if amt>=G
    $ans=[$ans,num].min
  else
    if questions==[]
      x,q,tot=highest
      if G-amt<=x*(q-1)
        $ans=[$ans,num+((G-amt).to_f/x).ceil].min
      end
      return
    end
    x,q,tot=questions[0]
    dfs(questions[1..-1],highest,amt+tot,num+q)
    dfs(questions[1..-1],questions[0],amt,num)
  end
end
dfs(ar,[],0,0)
p $ans
