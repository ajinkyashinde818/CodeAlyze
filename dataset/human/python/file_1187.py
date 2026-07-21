import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Data.List

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

main = do
    n <- getInt
    as <- getIntList
    print . minimum . tail . init $ zipWith (\x y -> abs (x - y)) (scanl (+) 0 as) (scanr (+) 0 as)
