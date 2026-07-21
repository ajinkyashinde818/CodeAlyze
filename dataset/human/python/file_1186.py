import qualified Data.Vector.Unboxed as V
import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)

main :: IO ()
main = do
    _ <- B.getLine
    as <- V.fromList . map (fst . fromJust . B.readInt) . B.words <$> B.getLine
    let t = V.sum as
        bs = V.scanl1 (+) as
        cs = V.map (\x -> t - x) bs
        ds = V.zipWith (\x y -> abs (x - y)) bs cs
    print $ V.minimum $ V.init ds
