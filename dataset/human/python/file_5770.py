import qualified Data.ByteString.Char8 as BS
import Data.Maybe

solve :: Int -> [Int] -> [Int] -> [Int] -> Int
solve _ [] _ _ = 0
solve prev (a:as) bs cs
    | a - prev == 1 = (cs !! prev) + (bs !! a) + solve a as bs cs
    | otherwise     = (bs !! a) + solve a as bs cs

r = fst . fromJust . BS.readInt

main = do
    _  <- getLine
    as <- map ((\x -> x-1) . r) . BS.words <$> BS.getLine
    bs <- map r . BS.words <$> BS.getLine
    cs <- map r . BS.words <$> BS.getLine
    print $ (bs !! head as) + solve (head as) (tail as) bs cs
