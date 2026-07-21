import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM
import qualified Data.ByteString.Char8 as BS
import Control.Monad
import Data.List

main :: IO ()
main = do
    (k,n) <- (\vec -> (vec VU.! 0, vec VU.! 1)) . VU.unfoldrN 2 readInt <$> BS.getLine
    as <- VU.unfoldrN n readInt <$> BS.getLine
    let bs = VU.toList as
    let ans = max (fun bs) (VU.head as - VU.last as + k)
    print $ k-ans

fun :: [Int] -> Int
fun xs = maximum $ zipWith (-) (tail xs) xs


readInt :: BS.ByteString -> Maybe (Int,BS.ByteString)
readInt xs = do
    (x,ys) <- BS.readInt xs
    return (x,BS.tail ys)
