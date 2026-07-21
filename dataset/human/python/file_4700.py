module Main where

import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
    [ss, ts] <- replicateM 2 getLine
    let ss' = sort ss
    let ts' = sortBy (flip compare) ts
    if ss' < ts'
        then putStrLn "Yes"
        else putStrLn "No"
