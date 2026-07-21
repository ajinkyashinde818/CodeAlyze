{-# LANGUAGE BangPatterns #-}

import qualified Data.Vector.Unboxed as V
import Data.Array.IArray (listArray, accumArray, (!))
import Data.Array.MArray
import Data.Array.ST (STUArray, runSTUArray)
import Data.Array.Unboxed (UArray)
import Data.List (sortOn, sortBy, unfoldr, partition,minimumBy)
import Data.Char (isSpace)
import Control.Monad.ST (ST)
import Control.Monad.Trans.State (StateT(..))
import Control.Arrow ((***))
import qualified Data.ByteString.Char8 as B

import Debug.Trace (trace)

-- utility functions

tr x = trace (show x) x

--   Input functions
readInt = B.readInt . B.dropWhile isSpace

readInts :: Int -> B.ByteString -> [Int]
readInts n = take n . unfoldr readInt

readIntsV :: Int -> B.ByteString -> V.Vector Int
readIntsV n = V.unfoldrN n readInt

readIntsA :: Int -> B.ByteString -> UArray Int Int
readIntsA n bs = runSTUArray $ do
  arr <- newArray_ (0,n-1)
  go arr 0 bs
  return arr
  where
    go :: STUArray s Int Int -> Int -> B.ByteString -> ST s ()
    go arr i bs
      | i==n = return ()
      | otherwise = do
        let Just (x,bs') = readInt bs
        writeArray arr i x
        go arr (i+1) bs'

readTsV :: Int -> B.ByteString -> V.Vector (Int,Int)
readTsV n = V.unfoldrN n $ runStateT ((,) <$> StateT readInt <*> StateT readInt)

readTs :: Int -> B.ByteString -> [(Int,Int)]
readTs n = take n . unfoldr readT where
  readT = runStateT ((,) <$> StateT readInt <*> StateT readInt)

-- main

calcSum ts = go ts 1 where
  go [] _ = []
  go ((p,c):ts) i = (p, i*p + (c`div`100)) : go ts (i+1)

inf = 10^10

minimumOn p = minimumBy f where
  f x y = p x `compare` p y

solv ts g = minimum.map fst.filter ((>=g).snd) $ go ts 1 where
  go [] _ = [(0,0)]
  go ((p,s):ts) i = concat [solveAll, solveSome, solveNothing]
    where
      solveAll = ((+p) *** (+s)) <$> go ts (i+1)
      solveSome :: [(Int,Int)]
      solveSome = solveSome' i <$> go ts (i+1)
      solveSome' i (num, point)
        | point >= g = (inf,0)
        | p>=need = (num+need, point+i*need)
        | otherwise = (inf, 0)
        where need = (g-point+(i-1)) `div` i
      solveNothing = go ts (i+1)

main = do
  [d,g] <- map read . words <$> getLine
  ts <- readTs d <$> B.getContents
  print $ solv (calcSum ts) (g`div`100)
