import           Control.Monad
import           Control.Monad.ST
import qualified Data.Array                  as A
import qualified Data.Array.ST               as ST
import qualified Data.Array.Unboxed          as AU
import           Data.Bits
import qualified Data.ByteString.Char8       as BS
import           Data.Char
import           Data.Int
import qualified Data.IntMap                 as IM
import           Data.List
import qualified Data.Map                    as M
import           Data.Maybe
import           Data.Ord
import qualified Data.Set                    as S
import           Data.Time
import qualified Data.Vector                 as V
import qualified Data.Vector.Mutable         as VM
import qualified Data.Vector.Unboxed         as VU
import qualified Data.Vector.Unboxed.Mutable as VUM

readInt :: IO [Int]
readInt = map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine

readInts :: Int -> IO [[Int]]
readInts n = replicateM n readInt

readInteger :: IO [Integer]
readInteger = map (fst . fromJust . BS.readInteger) . BS.words <$> BS.getLine

readIntegers :: Int -> IO [[Integer]]
readIntegers n = replicateM n readInteger

readString :: IO [String]
readString = map BS.unpack . BS.words <$> BS.getLine

readStrings :: Int -> IO [[String]]
readStrings n = replicateM n <$> readString

toPair :: [a] -> (a, a)
toPair [x, y] = (x, y)

count :: Eq a => a -> [a] -> Int
count a as = length $ filter (== a) as

main = do
  readInt
  s <- getLine
  print $ solve s

solve s = f sortedS 1 `mod` (10 ^ 9 + 7)
  where
    ans = product s'
    s' = map ((+ 1) . (`count` s)) sortedS
    sortedS = sort s

f [] acc = acc - 1
f aas@(a:as) acc = f (dropWhile (== a) as) ((1 + length aas - length (dropWhile (== a) as)) * (acc `mod` (10 ^ 9 + 7)))
