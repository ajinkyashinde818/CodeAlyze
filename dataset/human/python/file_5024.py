-- Try AtCoder
-- author: Leonardone @ NEETSDKASU

import qualified Data.IntSet as S

main = printAns . solve . map (map read . words) . lines =<< getContents

printAns c = putStrLn $ if c then "IMPOSSIBLE" else "POSSIBLE"

solve ((n:_):xs) = ans where
    ans = S.null $ uncurry S.intersection $ foldl f (S.empty, S.empty) xs
    f s@(s1, sN) [x,y] 
        | x == 1    = (S.insert y s1, sN)
        | y == n    = (s1, S.insert x sN)
        | otherwise = s
