import Data.Array.IO
import Data.List
import Data.IORef
import Data.Bits
import Control.Monad

main = do
  (n:m:_) <- getLine >>= return . (map read) . words :: IO [Int]
  arr <- newArray (2,n-1) 0 :: IO (IOArray Int Int)
  ch <- newIORef False :: IO (IORef Bool)
  
  let
    g = \(a:b:_) -> do
      when (a==1) $ do
        r <- readArray arr b
        writeArray arr b (r .|. 1) 
        when (r .&. 2 /= 0) (writeIORef ch True)
      when (b==n) $ do
        r <- readArray arr a
        writeArray arr a (r .|. 2)
        when (r .&. 1 /= 0) (writeIORef ch True)

  replicateM_ m (getLine >>= g . (map read) . words)

  putStrLn =<< return . func =<< readIORef ch

  where
    func False = "IMPOSSIBLE"
    func True = "POSSIBLE"
