import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Data.List

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

main = do
    [r,g,b,n] <- getIntList
    print $ length [()| r' <- [0..(n `div` r)], g' <- [0..((n-r*r') `div` g)], (n - r*r' - g*g') `mod` b == 0]
