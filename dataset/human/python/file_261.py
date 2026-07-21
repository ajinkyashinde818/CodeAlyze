import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as M
--import qualified Data.Vector as V
--import qualified Data.Vector.Mutable as VM

getBysplit = map read . words <$> getLine

main :: IO()
main = do
  n <- readLn :: IO Int
  l <- getBysplit :: IO [Int]
  print $ solve l


solve :: [Int] -> Int
solve lst = let
              ls = (sort . filter (<0)) lst
              bs = (sort . filter (>=0)) lst
              ans = if even $ length ls
                    then sum bs - sum ls
                    else let
                          temp1 = sum $ init ls
                          temp2 = if length bs > 0 then sum $ tail bs else 0
                          temp3 = if length bs > 0
                                  then  if - last ls > head bs then - last ls - head bs else last ls + head bs
                                  else last ls
                          in - temp1 + temp2 + temp3
              in ans
