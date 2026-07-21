{-# LANGUAGE ScopedTypeVariables, LambdaCase #-}

import qualified Data.List as List
import qualified Data.Set as Set

main :: IO ()
main = do
    [a, b]<- words <$> getContents
    if a < b then putStrLn "<"
    else if a > b then putStrLn ">"
    else putStrLn "="
