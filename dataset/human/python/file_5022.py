{-# OPTIONS_GHC -O #-}

import Control.Monad
import Data.List
import qualified Data.ByteString.Lazy.Char8 as B
import qualified Data.IntMap as M
import qualified Data.Set as S

readIntLL = map(unfoldr(B.readInt.B.dropWhile(==' '))).B.lines<$>B.getContents

insm2 n a b m
    | a==1 || a==n = insm b a m
    | b==1 || b==n = insm a b m
    | True = m

insm a b m = (M.insert a $ case M.lookup a m of
                Just s -> S.insert b s
                Nothing -> S.singleton b) m

f m n a = case M.lookup a m of
    Nothing -> False
    Just s -> S.member 1 s && S.member n s

main=do
    [n,m]:abs <- readIntLL
    --
    putStrLn $ if or $ map (f (mp n $ take m abs) n) [2..n-1] then "POSSIBLE" else "IMPOSSIBLE"
    where
        mp n abs = foldl' (\m [a,b]->insm2 n a b m) M.empty abs
