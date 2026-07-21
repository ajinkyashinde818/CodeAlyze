import           Control.Monad
import           Control.Monad.ST
import qualified Data.Array                    as A
import qualified Data.Array.Unboxed            as AU
import qualified Data.ByteString.Char8         as BS
import           Data.Char
import           Data.Int
import           Data.List
import           Data.Maybe
import           Data.Ord
import           Data.Time
import qualified Data.Vector                   as V
import qualified Data.Vector.Mutable           as VM
import qualified Data.Vector.Unboxed           as VU
import qualified Data.Vector.Unboxed.Mutable   as VUM

readIntegers :: IO [Integer]
readIntegers = map (fst . fromJust . BS.readInteger) . BS.words <$> BS.getLine

readIntegerLists :: Int -> IO [[Integer]]
readIntegerLists n =
  replicateM n (map (fst . fromJust . BS.readInteger) . BS.words <$> BS.getLine)

readInts :: IO [Int]
readInts = map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine

readIntLists :: Int -> IO [[Int]]
readIntLists n =
  replicateM n (map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine)

readStrings :: IO [String]
readStrings = map BS.unpack . BS.words <$> BS.getLine

readStringLists :: Int -> IO [[String]]
readStringLists n = replicateM n (map BS.unpack . BS.words <$> BS.getLine)

toPair :: [a] -> (a, a)
toPair [x, y] = (x, y)

checkPerformance action = do
  x <- getCurrentTime
  action
  y <- getCurrentTime
  return $ diffUTCTime y x

main :: IO ()
main = do
  [k, s] <- readInts
  print $ solve k s

solve :: Int -> Int -> Int
solve k s = length
  [ () | x <- [0 .. k], y <- [0 .. k], let z = s - x - y, z >= 0, z <= k ]
