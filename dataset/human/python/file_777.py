import qualified Data.Vector.Unboxed as U
import qualified Data.Vector as V
import qualified Data.ByteString.Char8 as C
import Debug.Trace
import Data.List
import Control.Monad
import Data.Ord


r :: Int -> IO (U.Vector Int)
r n = U.unfoldrN n (C.readInt . C.dropWhile (==' ')) <$> C.getLine

r' :: IO [Int]
r'  =   unfoldr    (C.readInt . C.dropWhile (==' ')) <$> C.getLine

rp :: IO (Int,Int)
rp  = toTup . unfoldr    (C.readInt . C.dropWhile (==' ')) <$> C.getLine

toTup [a,b] = (a,b)



main :: IO ()
main = do
    [n,r] <- r'
    print $ if n >= 10 then r else r + 100 * (10 - n)
