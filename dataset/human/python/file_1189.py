import           Control.Monad
import qualified Data.Array.IO               as IO
import           Data.Bits
import qualified Data.ByteString.Char8       as BS
import           Data.Char
import           Data.Foldable
import           Data.List
import           Data.Maybe
import qualified Data.Sequence               as Seq
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

main = do
  n <- getInt
  as <- getIntVec n

  d <- VM.new (n+1)
  VM.write d 0 (0::Int)

  forM_ [1..n] $ \i -> do
    let ai = as V.! (i-1)
    t <- VM.read d (i-1)
    VM.write d i (t + ai)

  d' <- V.freeze d
  let total = d' V.! n

  let solve i res
        | i == n   = res
        | otherwise = let s = d' V.! i
                          diff = abs (total - 2*s)
                          res' = min res diff
                      in solve (i+1) res'

  print $ solve 1 (10^18::Int)
