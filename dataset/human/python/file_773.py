import           Control.Monad
import qualified Data.ByteString.Char8 as BS
import           Data.Maybe

import           Control.Monad
import qualified Data.ByteString.Char8 as BS
import           Data.Maybe

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

main = do
  [n, r] <- getIntList
  print $ if n >= 10 then r else r + 100*(10-n)
