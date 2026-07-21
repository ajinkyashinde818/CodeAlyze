import qualified Data.Vector.Unboxed as V
import Data.Array.IArray (listArray, accumArray, (!))
import Data.Array.MArray
import Data.Array.ST (STUArray, runSTUArray)
import Data.Array.Unboxed (UArray)
import Data.List (sortOn, sortBy, unfoldr, partition)
import Data.Char (isSpace)
import Control.Monad.ST (ST, runST)
import Control.Monad.Trans.State (StateT(..))
import qualified Data.ByteString.Char8 as B
import qualified  Data.Set as S
import Control.Arrow (first)

import Debug.Trace (trace)

-- utility functions

--tr x = trace (show x) x
tr = id

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

modular = 10^9 + 7

count "" arr = return ()
count (x:xs) arr = do
  c <- readArray arr x
  writeArray arr x (c+1)
  count xs arr

sub x arr = readArray arr x >>= writeArray arr x . pred

productm m [] = 1
productm m (x:xs) = (x * productm m xs) `mod` m

solv s = runST $ do
  alphanum <- newArray ('a','z') 0 :: ST s (STUArray s Char Int)
  count s alphanum
  go s alphanum
  where
    p c v = fst v/=c && snd v > 0
    go "" alphanum = return 0
    go (x:xs) alphanum = do
      sub x alphanum
      counts <- map snd . filter (p x) <$> getAssocs alphanum
      r <- go xs alphanum
      let choice = productm modular $  map succ counts
      return $ (r + choice) `mod` modular

main = do
  getLine
  s <- getLine
  print $ solv s
