module Main where

import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
    getLine
    as <- fmap read . words <$> getLine :: IO [Int]
    let summ = sum as
    let cs = scanl1 (+) (init as)
    let ds = fmap (`subtract` summ) cs
    let es = zipWith (\c d -> abs $ c - d) cs ds
    let ans = minimum es
    print ans
