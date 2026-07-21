import Data.Array

main::IO()
main = do
  nmc<-getLine
  let n:m:[]= map read (words nmc) ::[Int]
  pica<-get_mat n
  picb<-get_mat m
  putStr ((if(checker pica picb n m) then "Yes" else "No")++"\n")


get_nline::Int -> IO([String])
get_nline 0 = return []
get_nline n = do
  d<-getLine
  rest<-get_nline (n-1)
  return (d:rest)

get_mat::Int -> IO (Array (Int,Int) Char)
get_mat n = do
  dat<-get_nline n
  return (listArray ((0,0),(n-1,n-1)) (concat (map (take n) dat)))



init_shifts::Int -> Int ->[(Int,Int)]
init_shifts n m = [(i,j)|i<-[0..(n-m)],j<-[0..(n-m)]]

--画像二つとそのサイズをうけて、シフト可能性のもとで一致すること。
checker::(Array (Int,Int) Char) -> (Array (Int,Int) Char) -> Int -> Int -> Bool
checker pic_A pic_B n m = let shifts = init_shifts n m in
                          let check_coord = [(x,y)|x<-[0..(m-1)],y<-[0..(m-1)]] in
                          (foldr extract shifts check_coord)/=[]
                            where extract (l,m) sft = filter (\(a,b)-> (pic_A!(l+a,m+b))==(pic_B!(l,m)) ) sft
