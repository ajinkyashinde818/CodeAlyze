import Control.Applicative
import Control.Monad
import Data.List
import Data.Array
import Data.Char

main = do
  n <- (read::String -> Int) <$> getLine
  perm <- map (read::String -> Int) . words <$> getLine
  scores <- listArray (1, n) . map (read::String -> Int) . words <$> getLine
  combis <- listArray (1, n) . map (read::String -> Int) . words <$> getLine
  print . fst $ foldl (\(sum, prv) crt -> if crt == prv + 1 then (sum + scores ! crt + combis ! prv, crt) else (sum + scores ! crt, crt)) (0, -1) perm
