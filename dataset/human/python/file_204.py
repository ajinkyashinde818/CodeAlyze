module Main where

import Control.Applicative
import Control.Monad
import Data.Function
import Data.List
import Data.Maybe

getK :: Int -> Maybe Int
getK n = get 0
    where get k | ss < 2 * n = get (k + 1)
                | ss == 2 * n = Just k
                | otherwise = Nothing
                where ss = k * (k - 1)

solve :: Int -> Maybe [[Int]]
solve n = getK n >>= gen
    where gen k = Just . map (map snd) . groupBy ((==) `on` fst) $ sort vs
              where is = [i | i <- [1 .. k], j <- [i + 1 .. k]] :: [Int]
                    js = [j | i <- [1 .. k], j <- [i + 1 .. k]] :: [Int]
                    vs = (zip is [1 .. n]) ++ (zip js [1 .. n])

main :: IO ()
main = do
  n <- read <$> getLine
  case (solve n) of
    Just ss -> do putStrLn "Yes"
                  print $ length ss
                  forM_ ss $ \s -> do
                    putStrLn . unwords . map show $ (length s):s
    Nothing -> putStrLn "No"
