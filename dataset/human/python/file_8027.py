import           Control.Monad
import           Data.IORef
import           Data.List.Split
import           Data.Maybe
import           Data.List

main :: IO ()
main = do
  [k, s] <- map read . words <$> getLine

  print $ length
    [ 0 | x <- [0 .. k], y <- [0 .. k], k >= s - (x + y) && 0 <= s - (x + y) ]
