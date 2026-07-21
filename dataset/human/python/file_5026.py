import Control.Monad
import Control.Monad.Primitive (PrimState)
import qualified Data.Vector.Unboxed as V
import qualified Data.Vector.Unboxed.Mutable as MV
import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)

type BVec = MV.MVector (PrimState IO) Bool

main :: IO ()
main = do
    [n, m] <- map (fst . fromJust . B.readInt) . B.words <$> B.getLine
    mv1 <- MV.replicate n False :: IO BVec
    mv2 <- MV.replicate n False :: IO BVec
    replicateM_ m $ do
        [a, b] <- map (fst . fromJust . B.readInt) . B.words <$> B.getLine
        when (a == 1) $ MV.unsafeWrite mv1 (b - 1) True
        when (b == n) $ MV.unsafeWrite mv2 (a - 1) True
    v1 <- V.unsafeFreeze mv1
    v2 <- V.unsafeFreeze mv2
    putStrLn $ if V.or (V.zipWith (&&) v1 v2) then "POSSIBLE" else "IMPOSSIBLE"
