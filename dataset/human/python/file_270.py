--prewritten code: https://github.com/antma/algo
{-# LANGUAGE BangPatterns #-}
{-# Options_GHC -O2 #-}
import Data.ByteString.Builder
import Data.Monoid
import System.IO
import qualified Data.ByteString.Char8 as C
import Data.Char
import Data.Array
import qualified Data.Array.Unboxed as UA
import Data.Int

ru, ri :: C.ByteString -> Int

ru = C.foldl' (\a c -> a * 10 - 48 + ord c) 0
ri s
  | C.head s == '-' = negate $ ru $ C.tail s
  | otherwise = ru s

solve :: [Int] -> Builder
solve (n:z) = (int64Dec $fst $ x ! 0) <> char7 '\n'
  where
    a :: UA.UArray Int Int
    a = UA.listArray (0, n - 1) $ take n z
    f :: Int -> (Int64, Int64)
    f !k = (max (v0 + w) (v1 - w), max (v0 - w) (v1 + w))
      where
        (!v0, !v1) = x ! (succ k)
        !w = fromIntegral $! a UA.! k
    x = listArray (0, n) $ (map f [ 0 .. n - 1]) ++ [(0, div minBound 2)]

main :: IO ()
main = hPutBuilder stdout . solve . map ri . C.words =<< C.getContents
