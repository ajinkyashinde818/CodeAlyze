import Data.List

main :: IO ()
main = do
       [k,n] <- (map read . words) <$> getLine
       a <- (sort . map read . words) <$> getLine
       print $ solve k a
       
solve :: Int -> [Int] -> Int
solve k as = let space = sub (as ++ [(head as) + k]) 0
             in  k - space
               
sub :: [Int] -> Int -> Int
sub [] n      = n 
sub [x] n     = n
sub (x:xs) n  = sub xs $ max n (abs $ (head xs) - x )
