import Data.List
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Control.Monad

main = do
	[k, s] <- getIntList
	print $ length $ [(x, y, z) | x <- [0..k], y <- [0..k], let z = s - x - y, z >= 0 && z <= k && x + y + z == s]

-- IO --
readInt :: BS.ByteString -> Int
readInt = fst . fromJust . BS.readInt

readIntList :: BS.ByteString -> [Int]
readIntList = map readInt . BS.words

getInt :: IO Int
getInt = readInt <$> BS.getLine

getIntList :: IO [Int]
getIntList = readIntList <$> BS.getLine
