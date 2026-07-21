import           Control.Monad
import           Control.Monad.ST
import qualified Data.Array                    as A
import qualified Data.Array.Unboxed            as AU
import qualified Data.Array.ST                 as ST
import qualified Data.ByteString.Char8         as BS
import           Data.Char
import           Data.Foldable                  ( toList )
import           Data.Int
import qualified Data.IntMap                   as IM
import           Data.List
import qualified Data.Map                      as M
import           Data.Maybe
import           Data.Ord
import qualified Data.Set                      as S
import qualified Data.Sequence                 as SQ
import           Data.Time
import qualified Data.Vector                   as V
import qualified Data.Vector.Mutable           as VM
import qualified Data.Vector.Unboxed           as VU
import qualified Data.Vector.Unboxed.Mutable   as VUM

readInt = map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine
readInts n = replicateM n readInt
readString = map BS.unpack . BS.words <$> BS.getLine
readStrings n = replicateM n readString
toPair [x, y] = (x, y)

main = do
  s     <- getLine
  [q]   <- readInt
  query <- readStrings q
  putStrLn $ solve s query

solve s = f (SQ.singleton s) True

f :: SQ.Seq String -> Bool -> [[String]] -> String
f s b [] | b         = concat $ toList s
         | otherwise = reverse $ concat $ toList s
f s b (q : qs) = case head q of
  "1" -> f s (not b) qs
  "2" -> f (g s b (tail q)) b qs

g :: SQ.Seq String -> Bool -> [String] -> SQ.Seq String
g s b q | (head q == "1" && b) || (head q == "2" && not b) = q !! 1 SQ.<| s
        | otherwise = s SQ.|> q !! 1
