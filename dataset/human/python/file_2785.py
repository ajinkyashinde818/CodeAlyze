import Control.Monad
import Data.Bits
main = do
  [n,k] <- map read . words <$> getLine
  abs <- replicateM (fromInteger n) $ map read . words <$> getLine
  let f x = sum [b | [a,b] <- abs, x.|.a == x]
  print $ maximum $ f k : [
    f (clearBit k i .|. 2^i-1) | i <- [1..29], testBit k i]
