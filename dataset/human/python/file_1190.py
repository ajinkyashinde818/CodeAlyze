import qualified Data.ByteString.Char8 as BS
import Data.Maybe (fromJust)
import Data.List


addAccum :: Integer -> Integer -> (Integer, Integer)
addAccum a b = (a + b, a + b)

solve :: [Integer] -> Integer
solve arr = minimum diff
    where
        p1 = init $ snd $ mapAccumL addAccum 0 arr
        p2 = tail $ snd $ mapAccumR addAccum 0 arr
        zp = zip p1 p2
        diff = map (\b -> abs ((fst b) - (snd b))) zp

main :: IO ()
main = do
    n <- fst . fromJust . BS.readInt <$> BS.getLine
    a <- map (fst . fromJust . BS.readInteger) . BS.words <$> BS.getLine
    print $ solve a
