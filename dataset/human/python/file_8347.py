import Data.Array
import Data.List

readInts :: IO [Int]
readInts = map read . words <$> getLine

main :: IO ()
main = do
  [k, n] <- readInts
  as <- listArray (1, n) . sort <$> readInts
  print $ solve k n as

solve :: Int -> Int -> Array Int Int -> Int
solve k n as = k - 
  (maximum [ (as ! (i + 1)) - (as ! i) | i <- [1..n-1] ]) `max` (as ! 1 - as ! n + k)
