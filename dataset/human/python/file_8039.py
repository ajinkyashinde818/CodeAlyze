import Control.Applicative
import Control.Monad

main :: IO ()
main = do
  [k, s] <- (map read . words) <$> getLine
  print . length $ satisfiedNums k s

satisfiedNums :: Int -> Int -> [Int]
satisfiedNums k s = do
  x<-[0..k]
  y<-[0..k]
  let z = s - (x + y)
  guard (0 <= z && z <= k)
  return z
