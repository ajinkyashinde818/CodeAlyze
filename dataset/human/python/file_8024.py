import Control.Monad
import Control.Applicative
import Data.List
import Data.Array
strToInt s = (read :: String -> Int) s

main = do
    [k,s] <- (map strToInt . words) <$> getLine
    let sn = [(x,y,s-x-y) | x <- [0..k] , y <- [0..k] , s-x-y >= 0 , s-x-y <= k]
    print (length sn)
