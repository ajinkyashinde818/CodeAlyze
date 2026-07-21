import Control.Monad
import Data.Array
main = do
  [n,m] <- map read . words <$> getLine
  a <- listArray ((1,1),(n,n)) . concat <$> replicateM n getLine
  b <- listArray ((1,1),(m,m)) . concat <$> replicateM m getLine
  putStrLn $ if or [
      and [b!(p,q) == a!(i+p-1,j+q-1) |
        p <- [1..m],
        q <- [1..m]] |
      i <- [1..1`max`(n-m)], 
      j <- [1..1`max`(n-m)]]
    then "Yes" 
    else "No"
