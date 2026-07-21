import Control.Applicative
import Control.Monad
import Data.List
import Data.Array
import Data.Char

main = do
  n <- (read::String -> Int) <$> getLine
  arr <- map (read::String -> Int) . words <$> getLine
  let all = sum arr
  let cumsum = init $ scanl1 (+) arr
  let diff = map (\val -> abs (all - 2 * val)) cumsum
  print $ minimum diff
