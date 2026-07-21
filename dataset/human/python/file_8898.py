import Data.List

main = do
  s <- reverse <$> getLine
  putStrLn $ f s

f :: String -> String
f [] = "YES"
f xs
  | "maerd" `isPrefixOf` xs = f $ drop 5 xs
  | "esare" `isPrefixOf` xs = f $ drop 5 xs
  | "remaerd" `isPrefixOf` xs = f $ drop 7 xs
  | "resare" `isPrefixOf` xs = f $ drop 6 xs
  | otherwise = "NO"
