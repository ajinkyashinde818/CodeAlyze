{-# LANGUAGE MultiWayIf #-}

import Data.Array.IO
import Control.Monad

main :: IO ()
main = do
  [n, m] <- (map read . words) <$> getLine :: IO [Int]
  a1 <- newArray (1, n) False :: IO (IOArray Int Bool)
  an <- newArray (1, n) False :: IO (IOArray Int Bool)
  replicateM_ m $ do
    [a, b] <- (map read . words) <$> getLine :: IO [Int]
    if
      | a == 1 -> writeArray a1 b True
      | b == 1 -> writeArray a1 a True
      | a == n -> writeArray an b True
      | b == n -> writeArray an a True
      | otherwise -> return ()

  check <- forM [1..n] $ \i -> do
        p1 <- readArray a1 i
        pn <- readArray an i
        return $ p1 && pn

  putStrLn $ if or check then "POSSIBLE" else "IMPOSSIBLE"
