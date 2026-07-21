import Data.List
import Control.Applicative

accumfunc :: [Int]->Int->[Int]
accumfunc (a:as) x = (a+2*x):a:as

listsumcut :: [Int]->[Int]->[Int]
listsumcut init list = tail $ foldl' accumfunc init list

solver (x:y:[]) = abs (x-y)
solver (x:xs) = minimum $ map abs $ listsumcut [x-(sum xs)] xs


main :: IO ()
main = do
    -- スペース区切り整数の入力
    getLine
    list <- map read . words <$> getLine
    -- 出力
    putStrLn $ show $ solver list
