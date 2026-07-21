import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Data.List
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

main = do
    [n,k] <- getIntList
    as <- VU.fromList . map pred <$> getIntList
    vec <- VUM.replicate n (-1 :: Int)
    let loop m a = do
            b <- VUM.read vec a
            if b < 0 then do
                VUM.write vec a m
                loop (m+1) (as VU.! a)
            else return (b,m)
    (s,t) <- loop 0 0
    let sim 0 a = a + 1
        sim m a = sim (m-1) (as VU.! a)
    print $ if k < t then sim k 0 else sim (s + (k-s) `mod` (t-s)) 0
