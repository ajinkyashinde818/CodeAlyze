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
  [n, k, s] <- getIntList

  when (k /= 0) $ putStr (show s)
  replicateM_ (k-1) $ putStr (" " ++ show s)

  let x = if s == 10^9 then 1 else s + 1

  when (k /= n) $ do
    if (k == 0)
      then putStr (show x)
      else putStr (" " ++ show x)
  replicateM_ (n - k - 1) $ putStr (" " ++ show x)

  putStrLn ""
