import Control.Monad
import Data.List
import Data.Bits
import Debug.Trace
import Data.Maybe
import qualified Data.ByteString.Char8 as C

main :: IO ()
main = do
  [n, m] <- readInts
  as <- getNLns n
  bs <- getNLns m
  putStrLn $ solve n m as bs

solve :: Int -> Int -> [String] -> [String] -> String
solve n m as bs =
  case foldM testMatch () genCandidates of
    Left  _ -> "Yes"
    Right _ -> "No"
  where
    d = n - m
    ds = [0 .. d]
    --
    testMatch _ (i, j) =
      let e = forM_ [0 .. m - 1] (\x ->
            if (drop j $ take (m + j) (as !! (i + x))) == bs !! x
              then Right ()
              else Left ()
            )
      in case e of
        Right _ -> Left ()
        Left  _ -> Right ()
    genCandidates :: [(Int, Int)]
    genCandidates = foldl' (\a x -> a ++ (zip (repeat x) ds)) [] ds


-- 以下ライブラリ

readInts :: IO [Int]
readInts = map (fst . fromJust . C.readInt) . C.words <$> C.getLine

readNInts :: Int -> IO [[Int]]
readNInts = flip replicateM readInts

readIntegers :: IO [Integer]
readIntegers = map (fst . fromJust . C.readInteger) . C.words <$> C.getLine

readNIntegers :: Int -> IO [[Integer]]
readNIntegers = flip replicateM readIntegers

getNLns :: Int -> IO [String]
getNLns = flip replicateM getLine

toTup2 :: [[a]] -> [(a, a)]
toTup2 = map (\ys -> case ys of y : z : zs -> (y, z))

encIdx2 :: Int -> (Int, Int) -> Int
encIdx2 mx (y, x) = y * mx + x

decIdx2 :: Int -> Int -> (Int, Int)
decIdx2 mx idx = (idx `div` mx, idx `mod` mx)

encIdx3 :: (Int, Int) -> (Int, Int, Int) -> Int
encIdx3 (my, mx) (z, y, x) = z * my * mx + y * mx + x

decIdx3 :: (Int, Int) -> Int -> (Int, Int, Int)
decIdx3 (my, mx) idx = (z, y, x)
  where
    basez = my * mx
    z = idx `div` basez
    y = (idx `mod` basez) `div` mx
    x = idx `mod` mx

while :: Monad m => m Bool -> m () -> m ()
while cond body = do
  b <- cond
  when b $ do
    body
    while cond body
