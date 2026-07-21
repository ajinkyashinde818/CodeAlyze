{-# LANGUAGE BangPatterns #-}
import           Control.Exception           (assert)
import           Control.Monad
import           Control.Monad.Primitive
import qualified Control.Monad.ST            as ST
import qualified Data.Array.IO               as IO
import qualified Data.Array.ST               as ST
import qualified Data.Array.Unboxed          as A
import           Data.Bits
import qualified Data.ByteString.Char8       as BS
import           Data.Char
import           Data.Foldable
import           Data.List
import qualified Data.Map.Strict             as Map
import           Data.Maybe
import qualified Data.Sequence               as Seq
import qualified Data.Set                    as Set
import qualified Data.Vector                 as VB
import qualified Data.Vector.Mutable         as VBM
import qualified Data.Vector.Unboxed         as V
import qualified Data.Vector.Unboxed.Mutable as VM
import           Debug.Trace

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine
getIntVec n = V.unfoldrN n (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine

readInteger = fst . fromJust . BS.readInteger
readIntegerList = map readInteger . BS.words
getInteger = readInteger <$> BS.getLine
getIntegerList = readIntegerList <$> BS.getLine

inf :: Int
inf = 10^18

primeFactorization :: Int -> [(Int, Int)]
primeFactorization x = pfact x 2 0 []
  where
    sr = floor $ sqrt $ fromIntegral x
    pfact n i r fs | i > sr    = if n > sr then (n,1):fs else fs
                   | otherwise =
                     if n `mod` i == 0
                     then pfact (n `div` i) i (r+1) fs
                     else pfact n (i+1) 0 (if r > 0 then (i,r):fs else fs)
main = do
  n <- getInt
  let pfs = primeFactorization n

      divE e i s | i + s > e = i - 1
                 | otherwise = divE e (i+1) (s+i)

      solve [] res = res
      solve ((p,e):xs) res = let c = divE e 1 0
                             in solve xs (res+c)

  print $ solve pfs 0
