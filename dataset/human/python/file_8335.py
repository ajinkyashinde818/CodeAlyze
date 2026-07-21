import Data.List

main = do
  [k, n] <- map read . words <$> getLine :: IO [Int]
  as <- map read . words <$> getLine :: IO [Int]
  let diffs = calcDiff as
      firstAndLast = (as !! 0) - (as !! (n-1)) + k
  print $ k - (head . reverse . sort $ (firstAndLast:diffs))

calcDiff :: [Int] -> [Int]
calcDiff [] = []
calcDiff (x1:[]) = []
calcDiff (x1:x2:xs) = (x2-x1) : calcDiff (x2:xs)
