import Control.Arrow
import Control.Monad
import Data.List
import qualified Data.ByteString.Char8 as B
import Data.Ord

main :: IO ()
main = getLine >> readLine >>= print . solve . sortBy cmpf
    where
        cmpf = comparing abs

solve :: [Int] -> Int
solve as
    | odd nc = sum bs - b 
    | otherwise = sum bbs
    where
        bbs@(b : bs) = map abs as
        nc = foldl' ff 0 as
        ff acc x
            | x < 0 = acc + 1
            | otherwise = acc 

readLine :: IO [Int]
readLine = unfoldr (fmap (second (maybe B.empty snd . B.uncons)) . B.readInt) <$> B.getLine

readContents :: Int -> IO [[Int]]
readContents = flip replicateM readLine
