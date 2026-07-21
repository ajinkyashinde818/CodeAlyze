import qualified Data.Vector.Unboxed as VU
import qualified Data.ByteString.Char8 as BS
import Control.Monad
import Data.List

add :: (Int,Int) -> (Int,Int) -> (Int,Int)
add (x,y) (z,w) = (x+z,y+w)

analyze :: Int -> VU.Vector (Int,Int) -> [Int] -> ((Int,Int),Int)
analyze d as xs = (sss, if xs == [0..d-1] then d else maximum $ ([0..d-1] \\ xs))
    where sss = foldl' add (0,0) [(100*(i+1)*(fst $ as VU.! i) + (snd $ as VU.! i),fst $ as VU.! i) | i <-xs]

fun :: (Int,Int) -> VU.Vector (Int,Int) -> Int -> ((Int,Int),Int) -> Int
fun (d,g) as n ((x,y),z) = if z == d then y
              else if g > x && n < first then fun (d,g) as (n+1) ((x+100*(z+1),y+1),z)
              else if g > x && n >= first then 2^20
              else y
              where first = fst $ as VU.! z


main :: IO ()
main = do
    (d,g) <- (\vec -> (vec VU.! 0, vec VU.! 1)) . VU.unfoldrN 2 readInt <$> BS.getLine
    as <- VU.replicateM d $ (\vec -> (vec VU.! 0, vec VU.! 1)) . VU.unfoldrN 2 readInt <$> BS.getLine
    print $ minimum $ map (fun (d,g) as 0) (map (analyze d as) (powerSet [0..d-1]))

powerSet :: [a] -> [[a]]
powerSet = filterM (\x -> [True,False]) 

readInt :: BS.ByteString -> Maybe (Int,BS.ByteString)
readInt xs = do
    (x,ys) <- BS.readInt xs
    return (x,BS.tail ys)
