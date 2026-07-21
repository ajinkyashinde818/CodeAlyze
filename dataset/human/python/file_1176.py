import Data.IORef
import Data.Array.IO
import Control.Monad

main :: IO ()
main = do
  n <- readLn :: IO Int
  prevRef <- newIORef 0
  as <- (map read . words) <$> getLine :: IO [Int]
  sum <- forM as $ \a -> do
    prev <- readIORef prevRef
    writeIORef prevRef (prev + a)
    return (prev + a)
  sumA <- newListArray (0, n - 1) sum :: IO (IOUArray Int Int)
  print =<< minimum <$> mapM (target sumA n) [0..n-2]

target :: IOUArray Int Int -> Int -> Int -> IO Int
target sumA n i = do
  y <- readArray sumA (n - 1)
  x <- readArray sumA i
  return $ abs (y - 2 * x)
