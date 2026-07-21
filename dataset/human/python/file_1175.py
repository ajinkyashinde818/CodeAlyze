import Control.Monad
import Control.Applicative
import Data.List
import Data.Array
strToInt s = (read :: String -> Int) s

main = do
    n <- readLn :: IO Int
    an <- map strToInt . words <$> getLine
    let s = sum an
    let sxn = reverse (tail (reverse (slist an)))
    let ans = [abs (2*x-s) | x <- sxn]
    
    print $ minimum ans

slist :: [Int] -> [Int]
slist an = reverse $ slist_ [] an
           where slist_ [] (a:an) = slist_ [a] an
                 slist_ sn [] = sn
                 slist_ sn (a:an) = slist_ ((a + head sn) : sn) an
                 --slist_ sn (a:an) = slist_ (sn ++ [(last sn) + a]) an
