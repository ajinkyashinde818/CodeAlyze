import Data.List
import qualified Data.ByteString.Char8 as BC
import Data.Maybe
import qualified Data.IntMap as IM

type Map = IM.IntMap Int

toTuple [a, b] = (a, b)

readIntsLines :: IO [(Int, Int)]
readIntsLines = map (toTuple . map (fst . fromJust . BC.readInt) . BC.words) . BC.lines <$> BC.getContents

solve :: [(Int, Int)] -> Int -> Map -> Bool
solve [] _ _ = False
solve ((a, b):xs) n m
  | a == 1 = solve xs n $ IM.insert b 1 m
  | b == n = IM.member a m || solve xs n m
  | otherwise = solve xs n m

main :: IO ()
main = do
  [n, m] <- map read . words <$> getLine
  ls <- sortOn fst <$> readIntsLines
  putStrLn $ if solve ls n IM.empty then "POSSIBLE" else "IMPOSSIBLE"
