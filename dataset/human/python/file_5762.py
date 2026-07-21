import Data.List
import Data.Maybe
import Control.Monad
import qualified Data.ByteString.Char8 as C

readInt' = fst.fromJust.C.readInt
readLnInt = map readInt'.C.words<$>C.getLine
readCsInt n = concat<$>replicateM n readLnInt

x ? (a,b) = if x then a else b
half = flip div 2
aliq = ((0==).).mod

main = do
 [n] <- readLnInt
 inputs <- replicateM 3 readLnInt
 print $ solve inputs

solve [a,b,c] = sum(b ++ [c!!ix|ix <- pick a])

pick (a:b:x)
 | a == b-1 = [a-1] ++ (null x)?([],pick(b:x))
 | otherwise = (null x)?([],pick(b:x))
