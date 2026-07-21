import Data.IntMap hiding (map, empty, insert, member)
import Data.IntSet hiding (map, fromList)
import Data.List hiding (insert)
import Data.Maybe

main :: IO ()
main = do
  l1 <- getLine
  l2 <- getLine
  let [n, k] = map read $ words l1 :: [Integer]
      a = fromList $ zip [1..] $ map read $ words l2 :: IntMap Int
      (lroute, loop_start) = g a empty [] 1
      loop_count = fromIntegral $ length lroute
      k' = if k > loop_count then (k - loop_start) `mod` (loop_count - loop_start) else k
      start = if k > loop_count then lroute !! (fromInteger loop_start) else 1
  -- print (loop_start, loop_count, k', start)
  print $ f a k' start

f as 0 x = x
f as 1 x = as ! x
f as k x = f as (k - 1) (as ! x)

g as visited route x = if x `member` visited then (reverse route, fromIntegral $ fromJust $ elemIndex x $ reverse route) else g as (insert x visited) (x:route) next
  where
    next = as ! x
