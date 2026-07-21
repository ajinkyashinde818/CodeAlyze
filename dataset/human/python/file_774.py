import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

main :: IO ()
main = do
    [n, r] <- getIntList
    putStrLn . show $ if n < 10 then r + 100 * (10-n) else r


readInt = fst . fromJust . BS.readInteger
readIntList = map readInt . BS.words
getIntList = readIntList <$> BS.getLine
getIntNList n = map readIntList <$> replicateM (fromIntegral n) BS.getLine
