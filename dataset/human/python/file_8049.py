import           System.IO hiding (char8)
import           Control.Applicative
import           Control.Monad
import           Data.List
import           Data.Tuple
import           Data.Int
import           Data.Char
import           Data.Maybe
import qualified Data.ByteString.Char8 as BS
import           Debug.Trace

-- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + --

main :: IO ()
main = do  
  (k, s) <- readInt2 <$> BS.getLine
  print $ f (k, s)

f :: (Int, Int) -> Int
f (k, s) = length r
  where
    r = [(x, y) | x <- [0..k], y <- [0..k], s - (x + y) <= k, s - (x + y) >= 0]
 
-- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + -- + --

readInt1 :: BS.ByteString -> Int
readInt1 = fst . fromJust . BS.readInt 
 
readInt2 :: BS.ByteString -> (Int,Int)
readInt2 = toTuple . readIntN
 
readIntN :: BS.ByteString -> [Int]
readIntN =  map readInt1 . BS.words
 
toTuple :: [a] -> (a, a)
toTuple [x, y] = (x, y)
