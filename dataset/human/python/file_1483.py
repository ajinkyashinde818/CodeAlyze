import           Control.Monad
import           Control.Applicative
import           Data.IORef
import           Data.List.Split
import           Data.Maybe
import           Data.List

main :: IO ()
main = do
  [n, m] <- map read . words <$> getLine
  img    <- replicateM n getLine
  timg   <- replicateM m getLine

  putStrLn $ if solve n m img timg then "Yes" else "No"

solve :: Int -> Int -> [String] -> [String] -> Bool
solve n m img timg
  | n < m
  = False
  | otherwise
  = isInfixOf timg (map (take m . drop (n - m)) img)
    || solve (n - 1) m img timg
