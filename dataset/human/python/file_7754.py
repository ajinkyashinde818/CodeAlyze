import Control.Monad
import qualified Data.ByteString.Char8 as BS
import Data.List
import Data.Maybe
import Data.Ord
import qualified Data.Vector as VC
import qualified Data.Vector.Mutable as VM

readNums = map (read . show . fst . fromJust . BS.readInteger) . BS.words <$> BS.getLine

readNumLists :: Int -> IO [[Integer]]
readNumLists n = replicateM n (map (read . show . fst . fromJust . BS.readInteger) . BS.words <$> BS.getLine)

readStrings :: IO [String]
readStrings = map BS.unpack . BS.words <$> BS.getLine

readStringLists :: Int -> IO [[String]]
readStringLists n = replicateM n (map BS.unpack . BS.words <$> BS.getLine)

toTuple :: [a] -> (a, a)
toTuple (x:y:_) = (x, y)

p s = putStr (show s ++ " ")

main :: IO ()
main = do
  (n:k:s:_) <- readNums
  mapM_ p (solve (fromIntegral n) (fromIntegral k) s)

solve :: Int -> Int -> Integer -> [Integer]
solve n k s
  | s < 10 ^ 9 = take n (replicate k s ++ repeat (s + 1))
  | otherwise = take n (replicate k s ++ repeat 1)
