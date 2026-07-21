import Data.List
import Control.Monad
import Control.Applicative


solver :: String  -> String
solver s
    | null s = "YES"
    | isPrefixOf "remaerd" s = solver $ drop 7 s
    | isPrefixOf "maerd"   s = solver $ drop 5 s
    | isPrefixOf "resare"  s = solver $ drop 6 s
    | isPrefixOf "esare"   s = solver $ drop 5 s
    | otherwise      = "NO"

main :: IO ()
main = getLine >>= (putStrLn . solver . reverse)
