import qualified Data.Vector.Unboxed as U
import qualified Data.Vector.Unboxed.Mutable as UM
import qualified Data.ByteString.Char8 as C
import Data.List
import Control.Monad
import Control.Arrow

r :: Int -> IO (U.Vector Int)
r n = U.unfoldrN n (C.readInt . C.dropWhile (==' ')) <$> C.getLine

r' :: IO [Int]
r'  =   unfoldr    (C.readInt . C.dropWhile (==' ')) <$> C.getLine


main = do
    [n,k] <- r'

    as <- r n
    reach <- U.thaw $ U.replicate n (-1)

    (posS,hdS,repS) <- count as reach 0 1
    let rm =  (k - hdS) `mod` repS 
    print $ if k < hdS then trace as 1 k else trace as posS rm 

count as reach ac pos = do
    h <- UM.read reach (pos-1)
    if h == -1
        then do 
            UM.write reach (pos-1) ac
            count as reach (ac+1) (as U.! (pos-1))
        else return (pos,h,ac-h)

trace as pos 0 = pos
trace as pos n = trace as (as U.! (pos-1)) (n-1)
