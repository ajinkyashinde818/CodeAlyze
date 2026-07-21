import Control.Monad.State
import Control.Monad
import Data.List

main = do
    s <- getLine
    q <- getLine >>= return . (read :: String -> Int)
    x <- replicateM q (getLine >>= return . words)
    let ((b,b'),c) = (runState $ foldl' (>>=) (return (s,"")) (map f x)) True
    if c then putStrLn (b ++ (reverse b')) else putStrLn (b' ++ (reverse b))

f :: [String] -> (String,String) -> State Bool (String,String)
f ["1"] (s,s') = do
    b <- get
    put $ not b
    return (s,s')

f x (s,s') = do
    b <- get
    return (if (x !! 1 == "1") == b then ((x !! 2 !!0:s),s') else (s,(x !! 2 !!0:s')))

{-
f :: [String] -> String -> State Bool String
f ["1"] s = do
    b <- get
    put $ not b
    return s

f x s = do
    b <- get
    return (if (x !! 1 == "1") == b then (x !! 2 !!0:s) else s ++ x !! 2)
-}
