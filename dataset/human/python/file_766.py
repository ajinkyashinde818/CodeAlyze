import Control.Monad.ST
import Data.Char


readInt :: IO Int
readInt = read <$> getLine :: IO Int

readIntSplit :: IO [Int]
readIntSplit = map read . words <$> getLine :: IO [Int]

readStr :: IO String
readStr = getLine

readStrSplit :: IO [String]
readStrSplit = map read . words <$> getLine

-- solve :: [Int] -> Int
-- solve [] = 1
-- solve (x:xs) = x * solve xs


solve :: Int -> Int -> Int
solve n r
  | n > 10 = r
  | otherwise = r + (100 * (10 - n))


main :: IO ()
main = do
  [n, r] <- readIntSplit
  print $ solve n r
