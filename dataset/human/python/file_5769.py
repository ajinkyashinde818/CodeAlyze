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
    bs <- getIntList
    cs <- getIntList
    print $ (sum bs) + (solve as cs)

solve [] _ = 0
solve [a] _ = 0
solve (a1 : a2 : as) cs | a2 - a1 == 1 = (cs !! (a1 - 1)) + solve (a2 : as) cs
                        | otherwise = solve (a2 : as) cs
