{-# LANGUAGE BangPatterns #-}

import Data.Bits
import Data.List
import GHC.Int

f :: Int64 -> Int64
f h = maxp 2 (h + 1) where
        maxp m n = if n `mod` m == 0 then m * maxp m (n `div` m) else 1

data Trie = Leaf { check :: Bool } | Branch { check :: Bool, left :: !Trie, right :: !Trie } deriving Show

empty = Leaf { check = False }

insertT :: Trie -> String -> Trie
insert Leaf { check = _ } ""  = Leaf { check = True } 
insertT Leaf { check = chk } (c:s') = 
    let !t' = insertT Leaf { check = False } s' in
        if c == '0'
        then Branch { check = chk, left = t', right = Leaf {check = False} }
        else Branch { check = chk, left = Leaf { check = False}, right = t'}

insertT b "" = b { check = True }
insertT b (c:s') = if c == '0'
                    then let !t' = insertT (left b) s' in b { left = t' } 
                    else let !t' = insertT (right b) s' in b { right = t' }

compute :: Trie -> Int64 -> Int64
compute t n = go t 0 where
                go Leaf {check = False} h = f $ n - h
                go Leaf {check = True}  h = 0
                go Branch { left = lft, right = rgt } h = (go lft $ h + 1) `xor` (go rgt $ h + 1)

insertMany :: [String] -> Trie -> Trie
insertMany slist t = foldl' insertT t slist 

arrayInput n xs = if n == 0 then return xs
                    else getLine >>= (\x -> arrayInput (n - 1) (x:xs))

main = do
    l <- getLine
    let [n, m] = map read $ words l :: [Int64]
    array <- arrayInput n []
    let t = compute (insertMany array empty) m
        res = if t == 0 then "Bob" else "Alice"

    putStrLn res
