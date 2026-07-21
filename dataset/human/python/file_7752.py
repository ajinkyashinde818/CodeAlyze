import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Data.List

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

main = do
    [n, k, s] <- getIntList
    let as | s < 10^9 = (replicate k s) ++ (replicate (n-k) (s+1))
           | s == 10^9 = (replicate k s) ++ (replicate (n-k) 1)
    putStrLn . unwords $ map show as
