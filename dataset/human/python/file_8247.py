import Data.Int (Int64)

judge :: Integral a => a -> [a] -> Bool
judge n xs = m == 0 && all f ys
    where
        (k, m) = sum xs `divMod` (n * (n + 1) `div` 2)
        ds = diff $ last xs : xs
        ys = fmap (k -) ds
        f x = x >= 0 && mod x n == 0

diff :: Num a => [a] -> [a]
diff xs = zipWith (-) (tail xs) (init xs)

main :: IO ()
main = do
    n <- readLn :: IO Int64
    xs <- fmap read . words <$> getLine :: IO [Int64]
    putStrLn $ if judge n xs then "YES" else "NO"
