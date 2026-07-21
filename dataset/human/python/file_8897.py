import Control.Monad
import Data.List

main=putStrLn =<< chk.reverse<$>getLine

chk s
    | isPrefixOf "resare"  s = chk $ drop 6 s
    | isPrefixOf "esare"   s = chk $ drop 5 s
    | isPrefixOf "remaerd" s = chk $ drop 7 s
    | isPrefixOf "maerd"   s = chk $ drop 5 s
    | s == "" = "YES"
    | otherwise = "NO"
