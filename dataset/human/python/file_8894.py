import Data.List

test [] = "YES"
test str@('m':sx) = if isPrefixOf "maerd" str
                    then test $ drop 5 str
                    else "NO"
test str@('r':sx) = if isPrefixOf "remaerd" str
                    then test $ drop 7 str
                    else if isPrefixOf "resare" str
                         then test $ drop 6 str
                         else "NO"
test str@('e':sx) = if isPrefixOf "esare" str
                    then test $ drop 5 str
                    else "NO"
test _ = "NO"

main = do
  l <- getLine
  let o = test $ reverse l
  putStrLn o
