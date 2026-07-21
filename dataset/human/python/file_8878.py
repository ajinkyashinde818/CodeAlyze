import Data.List (isPrefixOf)

main :: IO ()
main = do
  s <- getLine
  putStrLn $ hantei (reverse s)

hantei :: String -> String
hantei str
  | str == [] = "YES"
  | isPrefixOf "remaerd" str = hantei $ drop 7 str
  | isPrefixOf "maerd" str = hantei $ drop 5 str
  | isPrefixOf "resare" str = hantei $ drop 6 str
  | isPrefixOf "esare" str = hantei $ drop 5 str
  | otherwise = "NO"
