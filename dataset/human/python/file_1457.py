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
import           Data.Maybe
import qualified Data.Sequence               as Seq
import qualified Data.Set                    as Set
import qualified Data.Vector                 as VB
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

main = do
  [n, m] <- getIntList
  as <- VB.replicateM n BS.getLine
  bs <- VB.replicateM m BS.getLine

  let check y x = check' y x
        where check' i j
                | i == y + m  = True
                | otherwise =
                  let a = as VB.! i
                      ss = BS.take m $ BS.drop j a
                      b = bs VB.! (i - y)
                  in ss == b && check' (i+1) j

      solve y x | y > n - m = False
                | x > n - m = solve (y+1) 0
                | otherwise = check y x || solve y (x+1)

      ans = if solve 0 0 then "Yes" else "No"

  putStrLn ans
