import Data.Char (digitToInt)

f :: [Int] -> (Int, Int)
f [] = (0, 1)
f (x:xs)
  | x == 9    = (a + x, min (a + 1) b)
  | otherwise = (min (a + x) (b + x + 1), min (a + 10 - x) (b + 10 - (x + 1)))
  where (a, b) = f xs

main = do
  n <- map digitToInt <$> getLine :: IO [Int]
  let (a, b) = f n
  print $ min a (b + 1)
