import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Data.List
import qualified Data.Vector as V
import qualified Data.Vector.Mutable as VM
import qualified Data.Vector.Unboxed as VU
import qualified Data.Vector.Unboxed.Mutable as VUM

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

main = do
    [n,m] <- getIntList
    bridges <- VU.replicateM m $ do
        [a,b] <- getIntList
        return (a-1, b-1)
    let ns = V.create $ do
            vec <- VM.replicate n []
            VU.forM_ bridges $ \(a,b) -> do
                VM.modify vec (b:) a
                VM.modify vec (a:) b
            return vec
    let l2 = map (ns V.!) (ns V.! 0)
    putStrLn $ if any ((n-1) `elem`) l2 then "POSSIBLE" else "IMPOSSIBLE"
