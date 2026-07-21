import qualified Data.Map as M

f ::Int->Int->Int->Int->[(Int,Int)]
f n n2 b add
   |n<=n2=[(n2,n2*b+add)]
   |otherwise=(n2,n2*b):f n (n2+1) b add

f2 ::String->(Int,Int)
f2 x=let (a:b:[])=(map read . words) x::[Int]
     in (a,b `div` 100)

f3::[(Int,Int)]->[(Int,Int)]->[(Int,Int)]->[(Int,Int)]
f3 _ _ []=[]
f3 [] xs2 (y:ys)=f3 xs2 xs2 ys
f3 ((c1,p1):xs1) xs2 ((c2,p2):ys)=((c1+c2),(p1+p2)):(f3 xs1 xs2 ((c2,p2):ys))

f5::Int->Int->Int
f5 a b
 |a>b=a
 |otherwise=b

f4::Int->[(Int,Int)]->[(Int,Int)]->[(Int,Int)]
f4 _ [] ys=ys
f4 b1 ((c1,p1):xs) ys=let zs= (f c1 0 b1 p1)
                      in f4 (b1+1) xs (M.toList (M.fromListWith (f5) (f3 zs zs ys)))
f6 :: Int->[(Int,Int)]->Int
f6 _ []=1
f6 n ((c,p):xs)
    |n<=p=c
    |otherwise=f6 n xs

main = do
       a<-getLine
       b<-getContents
       let xs=lines b
           (n:m:[])=(map read . words) a::[Int]
           m2=m `div` 100
           ys=(map f2) xs
       --print $ f3 (f 3 0 1 5) (f 3 0 1 5) [(0,0)]
       print $ f6 m2 $ f4 1 ys [(0,0)]
