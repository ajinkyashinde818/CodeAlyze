{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}
import qualified Data.ByteString.Char8 as BS
import           Data.List             (subsequences, transpose)
import           Data.Maybe            (fromJust)
import           Data.Vector.Unboxed   (Vector, (!))
import qualified Data.Vector.Unboxed   as V

main :: IO ()
main = do
  [d, g] <- readInts <$> BS.getLine
  pcs <- map readInts . BS.lines <$> BS.getContents
  print $ solve d g pcs

solve :: Int -> Int -> [[Int]] -> Int
solve d g pcs = minimum . map (count d g ps' cs') $ subsequences [0 .. d-1] where
  [ps, cs] = transpose pcs
  ps' = V.fromList ps
  cs' = V.fromList cs

count :: Int -> Int -> Vector Int -> Vector Int -> [Int] -> Int
count d g ps cs is = count' d g' ps is + sum qs where
  g' = g - sum ds - sum (map (\i -> (i + 1) * 100 * ps!i) is)
  qs = map (ps !) is
  ds = map (cs !) is

count' :: Int -> Int -> Vector Int -> [Int] -> Int
count' d g ps is
  | i < 0         = 0
  | g <= 0        = 0
  | g - p * s > 0 = inf
  | otherwise     = (g + s - 1) `div` s where
      i = findProblemIndex d is
      p = ps ! i
      s = 100 * (i + 1)

findProblemIndex :: Int -> [Int] -> Int
findProblemIndex d is = go (d - 1) (reverse is) where
  go x [] = x
  go x (j:js)
    | x > j  = x
    | x == j = go (x - 1) js
    | x < j  = go x js

inf :: Int
inf = maxBound `div` 3

readInt :: BS.ByteString -> Int
readInt = fst . fromJust . BS.readInt

readInts :: BS.ByteString -> [Int]
readInts = map readInt . BS.words
