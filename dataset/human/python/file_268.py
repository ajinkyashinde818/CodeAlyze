import Data.List

toInt :: String -> Int
toInt = read :: String -> Int

countMinusElem :: [Int] -> Int
countMinusElem = length . filter (< 0)

main = do
  n <- toInt <$> getLine
  a <- map toInt . words <$> getLine
  let l = sort . map abs $ a
  putStrLn $ show $ if mod (countMinusElem a) 2 == 0
    then sum l
    else (sum $ tail l) - (head l)
