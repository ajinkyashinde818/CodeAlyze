import Data.List
import qualified Data.ByteString.Char8 as BC
import Data.Maybe

readIntsLine :: IO [Int]
readIntsLine = map (fst . fromJust . BC.readInt) . BC.words <$> BC.getLine

solve :: Int -> Int -> [Int] -> [Int]
solve _ _ [a] = []
solve curr total (a:as) = res : solve next total as
  where next = curr + a
        res = abs $ total - next * 2

main :: IO ()
main = do
  getLine
  as <- readIntsLine
  print . minimum $ solve 0 (sum as) as
