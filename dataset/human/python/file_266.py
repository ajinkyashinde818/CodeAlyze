import Control.Monad
import Control.Monad.ST
import qualified Data.Array as A
import qualified Data.Array.ST as ST
import qualified Data.Array.Unboxed as AU
import qualified Data.ByteString.Char8 as BS
import Data.Char
import Data.Int
import qualified Data.IntMap as IM
import Data.List
import qualified Data.Map as M
import Data.Maybe
import Data.Ord
import qualified Data.Set as S
import Data.Time
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM

readInt :: IO [Int]
readInt = map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine

readInts :: Int -> IO [[Int]]
readInts n = replicateM n readInt

readString :: IO [String]
readString = map BS.unpack . BS.words <$> BS.getLine

readStrings :: Int -> IO [[String]]
readStrings n = replicateM n <$> readString

toPair :: [a] -> (a, a)
toPair [x, y] = (x, y)

main = do
  [n] <- readInt
  a <- readInt
  print $ solve a

solve :: [Int] -> Int
solve a
  | even $ length (filter (< 0) a) = foldl (\acc n -> acc + abs n) 0 a
  | otherwise = foldl (\acc n -> acc + abs n) 0 a - minimum (map abs a) * 2
