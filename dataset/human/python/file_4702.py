import Control.Applicative
import Control.Monad
import Data.List
strToInt s = (read :: String -> Int) s

main :: IO ()
main = do
    s <- getLine
    t <- getLine
    let s' = sort s
    let t' = reverse $ sort t
    -- 出力
    putStrLn $ solve s' t'

solve :: String -> String -> String
solve xs [] = "No"
solve [] ys = "Yes"
solve (x:xs) (y:ys)
    | x == y = solve xs ys
    | x < y = "Yes"
    | otherwise = "No"
