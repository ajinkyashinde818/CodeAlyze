import Control.Monad
import qualified Data.Set as Set
main=do
 [n,m]<-map read.words<$>getLine
 ab<-replicateM m (words<$>getLine)
 putStrLn(k (show n) m ab Set.empty)
  where k _ 0 _ _ = "IMPOSSIBLE"
        k n m (["1",x]:l) s = if (Set.member x s) then"POSSIBLE"else(k n (m-1) l (Set.insert x s))
        k n m l s = if ((l!!0)!!1)==n then (if(Set.member ((l!!0)!!0) s) then"POSSIBLE"else(k n (m-1) (tail l) (Set.insert ((l!!0)!!0) s)))
                                      else (k n (m-1) (tail l) s)
