import Control.Applicative
import Data.List

main = do
  n <- readLn :: IO Int
  xs <- map read . words <$> getLine :: IO [Int]

  let
    a = n*(n+1)`div`2
    k = (sum xs) `div` a
    ys = zipWith (\x y -> x-y-k) xs (last xs : init xs)


  putStrLn $ if (sum xs) `mod` a == 0 && all (\y -> y `mod` n == 0 && y `div` n <= 0) ys then "YES" else "NO"
