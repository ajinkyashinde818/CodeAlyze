{-# LANGUAGE OverloadedStrings #-}
import Data.IORef
import Control.Monad
import qualified Data.ByteString as B
import qualified Data.ByteString.Char8 as BC

data Deque a = BD !Int [a] !Int [a]
  deriving Show

check :: Int -> [a] -> Int -> [a] -> Deque a
check lf f lr r
  | lf > 3*lr + 1, i <- div (lf + lr) 2, (f',f'') <- splitAt i f = BD i f' (lf + lr - i) (r ++ reverse f'')
  | lr > 3*lf + 1, j <- div (lf + lr) 2, (r',r'') <- splitAt j r = BD (lf + lr - j) (f ++ reverse r'') j r'
  | otherwise = BD lf f lr r
{-# INLINE check #-}

cons :: a -> Deque a -> Deque a
cons x (BD i xs j ys) = check (i + 1) (x : xs) j ys

snoc :: Deque a -> a -> Deque a
snoc (BD i xs j ys) x = check i xs (j + 1) (x : ys)

reverseQueue :: Deque a -> Deque a
reverseQueue (BD i xs j ys) = BD j ys i xs

toList :: Deque a -> [a]
toList (BD _ xs _ ys) = xs ++ reverse ys

main = do
    refStr <- B.getLine >>= newIORef . B.foldl' snoc (BD 0 [] 0 [])
    count <- readLn
    replicateM_ count $ do
        input <- BC.words <$> B.getLine
        case input of
            "1" : _ -> modifyIORef' refStr reverseQueue
            "2" : end : chr : _ -> 
                if end == "1"
                    then modifyIORef' refStr (cons (B.head chr))
                    else modifyIORef' refStr (`snoc` (B.head chr))
    readIORef refStr >>= B.putStrLn . B.pack . toList
