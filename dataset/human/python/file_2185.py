module Main where

import Control.Applicative
import Control.Monad
import Data.Maybe (catMaybes)

solve :: Int -> [(Int, Int, Int)] -> [Bool] -> Maybe Int
solve g ps qs = iter 0 0 Nothing (zip ps qs)
  where
    iter prob score Nothing [] = Just prob
    iter prob score (Just (i,p,c)) []
        | need <= 0   = Just prob
        | need > rmax = Nothing
        | otherwise   = Just (prob + k)
      where
        need = g - score
        rmax = 100 * i * (p - 1)
        k = head $ filter (\j -> 100 * i * j >= need) [1 .. p - 1]
    iter prob score rest (((i,p,c), False):rs)
        = iter prob score (Just (i,p,c)) rs
    iter prob score rest (((i,p,c), True):rs)
        = iter (prob + p) (score + (100 * i * p + c)) rest rs

main :: IO ()
main = do
    [d, g] <- fmap read . words <$> getLine :: IO [Int]
    ps <- forM [1 .. d] $ \i -> do
        [p, c] <- fmap read . words <$> getLine :: IO [Int]
        return (i, p, c)
    let ass = sequence $ replicate d [True, False]
    let ans = fmap (solve g ps) ass
    print $ minimum $ catMaybes ans
