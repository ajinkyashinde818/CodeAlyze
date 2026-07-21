import Control.Monad
import Data.List
import Data.Maybe
main=do
    (d:g:_)<-map read.words<$>getLine::IO[Int]
    pcs<-liftM (zip [1..]) $ replicateM d $ (\(p:c:_)->(p,c)).map read.words<$>getLine::IO[(Int,(Int,Int))]
    --
    print.minimum.mapMaybe (s g pcs) $ t [1..d]
--
s g pcs ns
    | cs >= g = Just cp
    | null res = Nothing
    | rn > rp = Nothing
    | True = Just (cp + rn)
    where
        (sel, res) = sp ns pcs
        (cs,cp) = f sel
        (ri,(rp,_)) = mx res
        rn = (((g-cs)`div`100)+ri-1) `div` ri

f = foldl' (\(a,s) (i,(p,c))->(a+100*i*p+c, s+p)) (0,0)

t [] = [[]]
t (x:xs) = concatMap (\u->[x:u,u]) $ t xs

sp ns = partition (\(i,_)->elem i ns)

mx :: [(Int,a)] -> (Int,a) 
mx = maximumBy (\(ai,_) (bi,_)->compare ai bi)
