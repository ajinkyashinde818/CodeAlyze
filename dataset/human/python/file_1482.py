import Control.Applicative
import Control.Monad
import qualified Data.ByteString.Char8 as B
import Data.Maybe (fromJust)
import Text.Printf
import Debug.Trace

getInts :: IO [Int]
getInts = map (fst . fromJust . B.readInt) . B.words <$> B.getLine

isin :: [String] -> [String] -> Int -> Int -> [()]
isin xs ys n m =
  [() |
    y <- [0..n-m],
    x <- [0..n-m],
    flip all [0..m-1] $ \yi ->
      flip all [0..m-1] $ \xi ->
      (xs!!(y+yi))!!(x+xi) == (ys!!yi)!!xi
      ]

main = do
  [n,m] <- getInts
  xs <- replicateM n getLine
  ys <- replicateM m getLine
  putStrLn $ if (isin xs ys n m) /= [] then "Yes" else "No"
