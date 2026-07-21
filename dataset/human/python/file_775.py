import Data.Char
import Data.List
import System.IO
import Control.Applicative
import Control.Monad
-- https://hoogle.haskell.org で関数検索

{- お客様の中でHaskellを書ける方はいらっしゃいますか？
    と、Haskellの例がなくて困っていたところを @tanakh さんに助けて頂きました。本当にありがとうございました。-}
main :: IO ()
main = do
    [n,r] <- getIntegerList 
    print $ r + 100* (max (10-n) 0)

    
 
 
 
 
 
 
same3 [a,b,c]
    | a==b && b==c = True
    | otherwise         = False       
       
diff3 [a,b,c] 
    | a==b = False
    | b==c = False
    | c==a = False
    | otherwise = True

yesno cond x 
    | cond x      = putStrLn "Yes"
    | otherwise = putStrLn "No"
    
    
    
{-

main = readLn >>= print . ceiling . (/2) 


(+) 3 $ (*) 4 4
-> 19
pure (+) <*> (Just 1) <*> ( Just 3)
-> Just 4

main = do 
    [a,b] <- getIntegerList 
    print $ (a*(a-1)+b*(b-1)) `div` 2
    -- / じゃなくて'div' ！！！！！

main = do
    s <- getLine    
    samecoffee s

samecoffee [x,y,a,b,c,d] 
    | a==b && c==d = do putStrLn "Yes"
    | otherwise         = do putStrLn "No"
samecoffee s = do putStrLn ""
         
putStrLn $ (show c) ++ " " ++ (show a) ++ " " ++ (show b)


main :: IO ()
main = do
    -- 整数の入力
    a <- readLn
    -- スペース区切り整数の入力
    [b, c] <- getIntegerList

    --[b, c] <- map read . words <$> getLine
    -- 文字列の入力
    s <- getLine
    -- 出力
    putStrLn $ show (a + b + c) ++ " " ++ s
-}

-- レイアウト規則

fac 0 = 1
fac n = n * fac (n-1)

-- FileName   : 164a
-- CreatedDate: 2020-04-26 20:56:13

--------------------------------------------  https://atcoder.jp/contests/abc164/submissions/12342628

getIntList        = map (read :: String -> Int) . words <$> getLine
getIntegerList    = map (read :: String -> Integer) . words <$> getLine
getIntegerListN m = map (read :: String -> Integer) <$> replicateM m getLine


base :: Integer
base = 1000000007

plus :: Integer -> Integer -> Integer
plus a b = (a+b) `mod` base

times :: Integer -> Integer -> Integer
times a b = a * b `mod` base

minus :: Integer -> Integer -> Integer
minus a b
   | a < b     = a-b + base
   | otherwise = a-b

power :: Integer -> Integer -> Integer
power n k
   | k == 0         = 1
   | k `mod` 2 == 0 = power (times n n) (k`div`2)
   | otherwise      = times n $! power n (k-1)

inv :: Integer -> Integer
inv n = power n $ base - 2

binom :: Integer -> Integer -> Integer
binom n m
   | (n-m) < m = times (foldr times 1 [m+1..n]) $ inv $ foldr times 1 [1..n-m]
   | otherwise = times (foldr times 1 [n-m+1..n]) $ inv $ foldr times 1 [1..m]
