import Data.List
main = getLine >>= print . solve . map read . words

solve :: [Int] -> Int
solve [k, s] = foldl' ff1 0 [0..k]
    where
        ff1 acc x = foldl' (ff2 x) acc [0..k]
        ff2 x acc y
            | x + y <= s && s <= x + y + k = acc + 1
            | otherwise = acc
