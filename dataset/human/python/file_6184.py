import Control.Monad
import Control.Applicative

main :: IO ()
main = do
  [m, n] <- getInts
  if (m == 0 && n == 0) then return ()
  else do
    ss <- getIntLines n
    print $ rolve m ss
    main

rolve m ss = bin_search (kuwa ss m) 1 1500000

kuwa xs m n = func xs m n n
  where
    func (x:xs) m n l
      | m <= 0 = False
      | m > 0 && xs == [] && n - x >= 0 = True
      | n - x >= 0 = func xs m (n - x) l
      | n - x < 0 = func (x:xs) (m - 1) l l

bin_search func min max
  | (max - min == 1) && (func min) = min
  | (max - min == 1) && (func max) = max
  | func center = bin_search func min center
  | not (func center) = bin_search func center max
  where
    center = div (min + max) 2
---

getInt :: IO Integer
getInt = read <$> getLine

getInts :: IO [Integer]
getInts = map read . words <$> getLine

getIntLines :: Integral a => a -> IO [Integer]
getIntLines n = replicateM (fromIntegral n :: Int) getInt
