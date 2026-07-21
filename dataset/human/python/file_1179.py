import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)
import qualified Data.Vector.Unboxed as V

main::IO()
main= do
    _ <- readLn::IO Int
    a <- V.fromList .  map (fst . fromJust . B.readInt) . B.words <$> B.getLine
    let elmnt = V.drop 1 $ V.zip (V.scanl (+) 0 (V.init a)) (V.scanr (+) 0 a)
    print $ V.minimum $ V.map (abs) $ V.map (\e -> (fst e - snd e)) elmnt
