{-# LANGUAGE BangPatterns #-}
module Main where
import qualified Data.Vector.Unboxed as U
import Data.Foldable (foldl')
main = do
  _ <- getLine
  xs <- U.fromList . map (pred . read) . words <$> getLine
  ys <- U.fromList . map read . words <$> getLine
  zs <- U.fromList . map read . words <$> getLine
  let go (!acc, !prev) i
        | i == prev + 1, Just b <- zs U.!? prev = (ys U.! i + b + acc, i)
        | otherwise = (ys U.! i + acc, i)

  print $ fst $ U.foldl' go (0 :: Int, -1 :: Int) xs
