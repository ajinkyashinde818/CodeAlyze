{-# LANGUAGE BangPatterns      #-} --引数に!
{-# LANGUAGE MultiWayIf        #-}
{-# LANGUAGE TupleSections     #-}

import Data.List

main :: IO ()
main = do
  _ <- getLine
  s <- getLine
  putStrLn $ show $ (foldl1' (\x y -> (mod0 $ x*y)) $ map (mod0.(+1).length) $ group $ sort s)-1

mod0 :: Int -> Int
mod0 n = if n < 1000000007 then n else mod n 1000000007
