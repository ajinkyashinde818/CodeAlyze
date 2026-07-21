import Control.Applicative
import Control.Monad
import Data.List
import Data.Char
strToInt s = (read :: String -> Int) s

main :: IO ()
main = do
    -- 文字列の入力
    s <- getLine
    -- 出力
    putStrLn $ if s!!0 == '9' || s!!1 == '9' then "Yes" else "No"
