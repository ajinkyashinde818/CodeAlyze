import Data.Bits (xor, (.&.))
import qualified Data.ByteString.Char8 as BS
import Control.Monad (replicateM)

data Tree = Node Int Bool Int Tree Tree
          | Empty Int
          deriving (Show)

coloredChildren :: Tree -> Int
coloredChildren (Empty _) = 0
coloredChildren (Node _ _ n _ _) = n

goDown :: Int -> BS.ByteString -> Tree -> Tree
goDown h s (Empty _)
  | BS.length s == 0 || BS.head s == '\n' = Node h True 1 (Empty (h+1)) (Empty (h+1))
  | BS.head s == '0' = Node h False 1 (goDown (h+1) (BS.tail s) (Empty (h+1))) (Empty (h+1))
  | otherwise = Node h False 1 (Empty (h+1)) (goDown (h+1) (BS.tail s) (Empty (h+1)))
goDown h s t@(Node _ c d l r)
  | BS.length s == 0 || BS.head s == '\n' = Node h True (d+1) l r
  | BS.head s == '0' = let l' = goDown (h+1) (BS.tail s) l
                       in Node h c (coloredChildren l' + coloredChildren r + if c then 1 else 0) l' r
  | BS.head s == '1' = let r' = goDown (h+1) (BS.tail s) r
                       in Node h c (coloredChildren l + coloredChildren r' + if c then 1 else 0) l r'

grundy :: Int -> Tree -> Int
grundy he (Empty h)
  | h > he = 0
  | otherwise = let x = he - h + 1 in x .&. (-x)
grundy _ (Node _ True _ _ _) = 0 -- 根が使われている場合
grundy he (Node h _ _ l@(Node _ _ 0 _ _) r@(Node _ _ 0 _ _)) = let x = he - h + 1 in x .&. (-x)
grundy he (Node _ _ _ l r) = grundy he l `xor` grundy he r

main = do
  [n, l] <- fmap (map read . words) getLine
  ss <- replicateM n BS.getLine
  let t = foldr (goDown 0) (Empty 0) ss
      g = grundy l t
  putStrLn $ if g /= 0 then "Alice" else "Bob"
