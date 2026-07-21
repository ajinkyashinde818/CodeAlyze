import Control.Monad
main=do
 [n,m]<-map read.words<$>getLine
 a<-replicateM n getLine
 b<-replicateM m getLine
 putStrLn(f a b 0 0 0 m (n-m+1))
  where f a b h i j m l |h==m ="Yes"
                        |i==l ="No"
                        |j>=l&&h==0 =f ((map (\x->(tail x)))a) b 0 (i+1) 0 m l
                        |otherwise =if (take m (a!!j))==b!!h then (f a b (h+1) i (j+1) m l)
                                                             else (f a b 0 i (j+1) m l)
