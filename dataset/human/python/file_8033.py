import Control.Applicative
import Control.Monad
import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)
import Text.Printf
import Debug.Trace

getInts :: IO [Int]
getInts = map (fst . fromJust . B.readInt) . B.words <$> B.getLine

solve x y k s a
  | x > k = a
  | y > k = solve (x+1) 0 k s a
  | otherwise = solve x (y+1) k s (a + (if 0 <= z && z <= k then 1 else 0))
  where z = s - x - y
                                           

main = do
  [k,s] <- getInts
  print $ solve 0 0 k s 0
