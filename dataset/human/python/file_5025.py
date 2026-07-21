import Data.Bool
import qualified Data.ByteString.Char8 as C
import Data.Maybe
import qualified Data.IntSet as S
import Data.Vector.Generic ((!))
import qualified Data.Vector.Unboxed as U

main = C.interact $ put . sol . get

get = U.unfoldr (C.readInt . C.dropWhile (<'0'))

put = C.pack . (++ "POSSIBLE") . bool "" "IM"

sol v = S.null via
  where
  n = v!0
  m = v!1
  u = U.drop 2 v
  es = U.unfoldrN m split2 u
  split2 u = Just ((min (U.head v) (U.last v), max (U.head v) (U.last v)), w)
    where (v,w) = U.splitAt 2 u
  e1 = S.fromList . U.toList . U.map snd $ U.filter ((==1) . fst) es
  en = S.fromList . U.toList . U.map fst $ U.filter ((==n) . snd) es
  via = S.intersection e1 en
