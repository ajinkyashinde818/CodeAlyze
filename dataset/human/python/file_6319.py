import           Control.Monad
import           Data.Array
import qualified Data.ByteString.Char8 as BS
import           Data.List
import           Data.Maybe
import           Data.Ord

readInts :: IO [Int]
readInts = map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine

main = do
  n <- read <$> getLine
  print $ solve n

solve :: Int -> Int
solve n
  | odd n = 0
  | otherwise = how (n `div` 2)

how 0 = 0
how n = m + how m
  where
    m = n `div` 5
