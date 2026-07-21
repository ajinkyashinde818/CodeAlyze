import Data.List
import Data.Ord

solve :: [(Char, Char)] -> Ordering
solve [] = EQ
solve ((c1, c2):cs)
  | c1 < c2 = GT
  | c1 > c2 = LT
  | otherwise = solve cs

main :: IO ()
main = do
  s <- sort <$> getLine
  t <- sortOn Down <$> getLine
  let result = solve $ zip s t
  putStrLn $ if result == GT || (result == EQ && length s < length t)
             then "Yes"
             else "No"
