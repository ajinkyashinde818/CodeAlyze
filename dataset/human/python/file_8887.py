import Data.List

main = do
  xs <- reverse <$> getLine
  putStrLn $ if solve xs then "YES" else "NO"

solve :: String -> Bool
solve "" = True
solve xs
  | isPrefixOf "remaerd" xs = solve $ drop 7 xs
  | isPrefixOf "maerd" xs   = solve $ drop 5 xs
  | isPrefixOf "resare" xs  = solve $ drop 6 xs
  | isPrefixOf "esare" xs   = solve $ drop 5 xs
  | otherwise = False
