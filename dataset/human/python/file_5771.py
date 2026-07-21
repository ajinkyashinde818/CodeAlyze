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
    n <- readLn
    as <- r n
    bs <- r n
    cs <- r (n-1)
    let ms = U.map ((bs U.!) . pred) as
    let ads = addit (U.head as) cs (U.tail as)
    --print ms
    --print ads
    print (U.sum ms + U.sum ads)


addit lst cs as
    | U.null as = U.empty
    | otherwise = let a = U.head as
            in U.cons (if lst+1 == a then cs U.! (a-2) else 0) (addit a cs (U.tail as))
