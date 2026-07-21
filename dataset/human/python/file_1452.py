import Data.Array.IO
import Data.IORef
import Control.Monad

main :: IO ()
main = do
  [n, m] <- (map read . words) <$> getLine :: IO [Int]
  imA <- newArray ((0, 0), (n - 1, n - 1)) '_' :: IO (IOUArray (Int, Int) Char)
  forM_ [0..n - 1] $ \i -> do
    row <- getLine
    forM_ [0..n - 1] $ \j -> writeArray imA (i, j) (row!!j)

  imB <- newArray ((0, 0), (m - 1, m - 1)) '_' :: IO (IOUArray (Int, Int) Char)
  forM_ [0..m - 1] $ \i -> do
    row <- getLine
    forM_ [0..m - 1] $ \j -> writeArray imB (i, j) (row!!j)

  checked <- check imA imB n m
  putStrLn $ if checked then "Yes" else "No"

check imA imB n m = do
  ng <- newIORef False
  forM_ [0..n - m] $ \x ->
    forM_ [0..n - m] $ \y -> do
      ident <- isIdent imA imB m x y
      when ident $ writeIORef ng True

  readIORef ng

isIdent :: IOUArray (Int, Int) Char -> IOUArray (Int, Int) Char -> Int -> Int -> Int -> IO Bool
isIdent imA imB m x y = do
  differ <- newIORef False
  forM_ [0..m - 1] $ \i ->
    forM_ [0..m - 1] $ \j -> do
      cellA <- readArray imA (x + i, y + j)
      cellB <- readArray imB (i, j)
      when (cellA /= cellB) $ writeIORef differ True

  not <$> readIORef differ
