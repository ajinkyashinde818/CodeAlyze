import qualified Data.Vector.Unboxed as U
import qualified Data.Vector as V
import qualified Data.ByteString.Char8 as C
import Debug.Trace
import Data.List
import Control.Monad
import Data.Ord
import Data.Maybe


r :: Int -> IO (U.Vector Int)
r n = U.unfoldrN n (C.readInt . C.dropWhile (==' ')) <$> C.getLine

r' :: IO [Int]
r'  =   unfoldr    (C.readInt . C.dropWhile (==' ')) <$> C.getLine


main :: IO ()
main = do
    [k,n] <- r'
    v <- r n
    let v2 = v U.++ U.map (+k) v
    print $ minimum $ [  v2 U.! (s+n-1)  -  (v2 U.! s) | s<-[0..n-1]]
