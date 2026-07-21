import qualified Data.ByteString.Char8 as BS
import Data.Maybe

readInt = fst . fromJust . BS.readInt

readIntList = map readInt . BS.words

getIntList = readIntList <$> BS.getLine

main = do
  [n, r] <- getIntList
  print $ if n >= 10 then r else (r + (10 - n) * 100)
