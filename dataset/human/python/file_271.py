import           Control.Monad.State
import qualified Data.ByteString.Char8 as BS
import           Data.Char
import           Data.List

getAsInt :: IO [Int]
getAsInt =  unfoldr (BS.readInt . BS.dropWhile isSpace) <$> BS.getLine

main :: IO ()
main = do
  _ <- getLine
  as <- getAsInt
  let solve = solve2
  print $ solve as

solve2 :: [Int] -> Int
solve2 (x:xs) = evalState go $ if x >= 0 then (-x,True,0,xs) else (x,False,0,xs)

go :: State (Int,Bool,Int,[Int]) Int
go = do
  (m,b,n,xs) <- get
  case xs of
    []     | b -> return $ n - m
           | otherwise -> return $ n + m
    (x:ys) | x >= 0 && - m >=   x -> put (-x,b    ,n-m,ys) >> go
           | x >= 0 && - m <    x -> put (m ,b    ,n+x,ys) >> go
           | x <  0 && - m >= - x -> put (x ,not b,n-m,ys) >> go
           | x <  0 && - m <  - x -> put (m ,not b,n-x,ys) >> go
