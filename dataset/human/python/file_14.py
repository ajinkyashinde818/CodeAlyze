import Control.Arrow
import Control.Monad
import Data.List
import qualified Data.ByteString.Char8 as B

main :: IO ()
main = readLine >>= print . solve

solve :: [Int] -> Int
solve [r, g, b, n] = length [(x, y) | x <- [0..(n `div` r)], y <- [0..(n `div` g)], n - r * x - g * y >= 0, (n - r * x - g * y) `mod` b == 0]

readLine :: IO [Int]
readLine = unfoldr (fmap (second (maybe B.empty snd . B.uncons)) . B.readInt) <$> B.getLine

readContents :: Int -> IO [[Int]]
readContents = flip replicateM readLine
