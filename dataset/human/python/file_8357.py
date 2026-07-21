import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)
import qualified Data.Vector.Unboxed as VU

getInts::IO[Int]
getInts = map (fst . fromJust . B.readInt) . B.words <$> B.getLine

main = do
  [k,n] <- map read . words <$> getLine
  an <- VU.fromList <$> getInts
  print $ k - max ((k+(VU.head an))-VU.last an) (VU.maximum $ VU.zipWith (-) (VU.tail an) an)
