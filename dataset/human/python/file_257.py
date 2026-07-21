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
    let z = 0 `elem` as
        m = length $ filter (< 0) as
        p = map abs as
        ans | z || even m = sum p
            | odd m = sum p - 2 * (minimum p)
    print ans
