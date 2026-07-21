import Control.Monad
import Data.Maybe (fromJust)
import Data.List
import Data.Char

isDayDream :: String -> Bool
isDayDream "" = True
isDayDream s
    | (isPrefixOf "maerd" s) = isDayDream (drop 5 s)
    | (isPrefixOf "remaerd" s) = isDayDream (drop 7 s)
    | (isPrefixOf "esare" s) = isDayDream (drop 5 s)
    | (isPrefixOf "resare" s) = isDayDream (drop 6 s)
    | otherwise =  False

toYesNo :: Bool -> String
toYesNo True = "YES"
toYesNo _ = "NO"

solve :: String -> String
solve = toYesNo . isDayDream . reverse

main :: IO ()
main = do
    s <- getLine
    putStrLn $ solve s
