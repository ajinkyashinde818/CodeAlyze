import Control.Applicative
import Control.Monad
import Data.List

cutrect :: Int -> Int -> Int -> Int -> [[a]] -> [[a]]
cutrect x y w h rect = map ((take w) . (drop x)) (take h (drop y rect))

yesno b = if b then "Yes" else "No"

main = do
  (n:m:_) <- (map read) . words <$> getLine
  a <- replicateM n getLine
  b <- replicateM m getLine

  putStrLn $ (yesno . (elem b) . concat) $ map (\y -> map (\x -> cutrect x y m m a) [0..n-m]) [0..n-m]
