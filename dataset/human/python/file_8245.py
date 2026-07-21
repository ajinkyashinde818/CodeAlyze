import Data.Bool (bool)

main :: IO ()
main = do
    n  <- read <$> getLine
    xs <- map read . words <$> getLine
    answer $ solve n xs

type Answer = Bool
answer :: Answer -> IO ()
answer = putStrLn . bool "NO" "YES"

solve :: Int -> [Int] -> Answer
solve n as = inner (as ++ [head as]) (m == 0)
  where
    (k, m) = sum as `divMod` ((n * n + n) `div` 2)
    inner (xa : xxs@(xb : xs)) =
        (&&) `flip` bool (inner xxs) id (null xs) (d <= 0 && d `mod` n == 0)
      where
        d = xb - xa - k
