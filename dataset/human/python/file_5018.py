module Main where

import Control.Applicative
import Control.Monad
-- import Data.List
import qualified Data.ByteString.Char8 as B
import Data.Array.IArray
import Data.Array.MArray
import Data.Array.ST

readi b | Just (n, _) <- B.readInt b = n

main :: IO ()
main = do
    [n, m] <- fmap read . words <$> getLine :: IO [Int]
    as <- fmap ((\[a, b] -> (readi a, readi b)) . B.words) . B.lines <$> B.getContents

    let a1 = runSTUArray $ do
            a <- newArray (1, n) False
            forM_ as $ \(i, j) -> do
                when (i == 1) $ writeArray a j True
            return a

    let a2 = runSTUArray $ do
            a <- newArray (1, n) False
            forM_ as $ \(i, j) -> do
                when (j == n) $ writeArray a i True
            return a

    let f i = and [a1 ! i, a2 ! i]

    if any f [2 .. n - 1]
        then putStrLn "POSSIBLE"
        else putStrLn "IMPOSSIBLE"
