import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Data.List

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

main = do
    [k, n] <- getIntList
    (a : as) <- getIntList
    let x = maximum $ zipWith (-) as (a : as)
    let y = k + a - (last as)
    print $ k - (max x y)
