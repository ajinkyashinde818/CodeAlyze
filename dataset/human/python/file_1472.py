import Control.Monad
match a b i j = let m = length b in b == (map (take m . drop j) . take m . drop i) a
main = do
    [n, m] <- map read . words <$> getLine
    a <- replicateM n getLine
    b <- replicateM m getLine
    putStrLn (if or [match a b i j | i <- [0..n-m], j <- [0..n-m]] then "Yes" else "No")
