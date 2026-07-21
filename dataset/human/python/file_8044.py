import Data.Char
import Data.List

solve :: Int -> Int -> Int
solve k s = solver 0 0
    where　solver x y
            | y > k = 0
            | x > k = 0
            | x == 0 = solver 0 (y+1) + solver 1 y + if (s-y)>=0 && (s-y) <= k then 1 else 0
            | otherwise = solver (x+1) y + if (s-x-y)>=0 && (s-x-y) <= k then 1 else 0

main = do
    [k,s] <- (map read . words) <$> getLine
    print $ solve k s
