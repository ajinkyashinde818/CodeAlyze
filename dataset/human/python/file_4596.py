-- haskell
import Data.List
import Debug.Trace

main = getContents >>= (putStrLn . show . ans)

ans :: String -> Int
ans str = maximum $  0 : [y - 1 | (x,y) <- zip hist [0,1..] , x + 1 >= y]
  where
    hist = take (n + 10) $ scanl (+) 0 diff_table
    diff_table = zipWith (-) as_table bs_table
    as_table = tail $ countList as_counted 0
    bs_table = countList bs_counted 0
    as_counted = map (\x -> (head x, length x)) . group $ as_sorted
    bs_counted = map (\x -> (head x, length x)) . group $ bs_sorted
    as_sorted = sort as
    bs_sorted = sort bs
    as = map head l
    bs = map (head . tail) l
    n = length l
    l = map (map read . words) . tail . lines $ str


countList :: [(Int, Int)] -> Int -> [Int]
countList [] _ = repeat 0
countList ((x,y):xs) i =
  if x == i then y : (countList xs (i + 1)) else 0 : (countList ((x,y) : xs) (i + 1))
