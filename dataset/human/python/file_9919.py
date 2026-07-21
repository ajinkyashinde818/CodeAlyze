import           Control.Monad
import           Data.Array
import qualified Data.ByteString.Char8 as BS
import           Data.List
import           Data.Maybe
import           Data.Ord

readInts :: IO [Int]
readInts = map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine

main = do
  [a,b] <- map read . words <$> getLine
  print $ lcm a b
