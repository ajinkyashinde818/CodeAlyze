import Control.Applicative
import Control.Monad
import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)
import Text.Printf
import Debug.Trace

getInts :: IO [Int]
getInts = map (fst . fromJust . B.readInt) . B.words <$> B.getLine

main = do
  [x] <- getInts
  putStrLn $ if x < 1200 then "ABC" else "ARC"
