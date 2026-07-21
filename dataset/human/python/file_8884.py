import Control.Applicative
import Control.Monad
import Data.List
import Data.Char
import Data.Maybe
strToInt s = (read :: String -> Int) s
strToInteger s = (read :: String -> Integer) s
strToDouble s = (read :: String -> Double) s

main :: IO ()
main = do
    -- 文字列の入力
    s <- reverse <$> getLine
    -- 出力
    putStrLn $ if solve s then "YES" else "NO"

solve :: String -> Bool
solve [] = True
solve xs = case take 2 xs of
    "re" -> if (reverse $ take 6 xs) == "eraser"
                then solve $ drop 6 xs
                else if (reverse $ take 7 xs) == "dreamer" then solve $ drop 7 xs
                     else False
    "es" -> if (reverse $ take 5 xs) == "erase"
                then solve $ drop 5 xs
                else False
    "ma" -> if (reverse $ take 5 xs) == "dream"
                then solve $ drop 5 xs
                else False
    otherwise -> False
