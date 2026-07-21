{-# OPTIONS_GHC -O #-}

import Control.Monad
import Data.List
import qualified Data.ByteString.Lazy.Char8 as B

readIntLL = map(unfoldr(B.readInt.B.dropWhile(==' '))).B.lines<$>B.getContents

psi (x,y) a = (x+a, y-a)

main=do
    [n]:(a:as):_ <- readIntLL
    --
    print $ minimum $ map (\(x,y) -> abs $ x-y) $ take (n-1) $ scanl' psi (a, sum as) as
