import           Control.Monad
import           Control.Monad.ST
import qualified Data.Array                    as A
import qualified Data.Array.Unboxed            as AU
import qualified Data.Array.ST                 as ST
import qualified Data.ByteString.Char8         as BS
import           Data.Char
import           Data.Int
import qualified Data.IntMap                   as IM
import           Data.List
import qualified Data.Map                      as M
import           Data.Maybe
import           Data.Ord
import qualified Data.Set                      as S
import           Data.Time
import qualified Data.Vector                   as V
import qualified Data.Vector.Mutable           as VM
import qualified Data.Vector.Unboxed           as VU
import qualified Data.Vector.Unboxed.Mutable   as VUM

readInt = map (fst . fromJust . BS.readInt) . BS.words <$> BS.getLine
readInts n = replicateM n readInt
readString = map BS.unpack . BS.words <$> BS.getLine
readStrings n = replicateM n $ BS.unpack <$> BS.getLine
toPair [x, y] = (x, y)

main = do
  [n, r] <- readInt
  print $ solve n r

solve n r | n >= 10   = r
          | otherwise = r + 100 * (10 - n)
