import Data.List
import Control.Applicative

main = do
  [k,s] <- map read . words <$> getLine :: IO [Int]
  print $ sum
   $ map (\x -> 1-s+x+k+k)
          [max 0 (s-k-k)..min k (s-k)]
   ++ map (\x -> 1+s-x)
           [max 0 (s-k+1)..min k (s-0-0)]
