import           Control.Monad
import qualified Data.ByteString.Char8       as BS
import           Data.Char
import           Data.Maybe
import qualified Data.Vector.Unboxed         as V
import qualified Data.Vector.Unboxed.Mutable as VM

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine
getIntVec n = V.unfoldrN n (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine

main = do
  [k, n] <- getIntList
  as <- getIntVec n

  let dist i | i == 0    = (as V.! 0) + (k - (as V.! (n-1)))
             | otherwise = (as V.! i) - (as V.! (i-1))

      calcMaxD i m | i == n    = m
                   | otherwise = calcMaxD (i+1) (max m (dist i))

      maxD = calcMaxD 0 0

      ans = k - maxD

  print ans
