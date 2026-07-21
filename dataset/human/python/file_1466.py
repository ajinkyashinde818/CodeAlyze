import Data.Bool
import Data.Char
import qualified Data.ByteString.Char8 as C
import Data.List

main = sol <$> geti <*> gets >>= put

geti = unfoldr (C.readInt . C.dropWhile (==' ')) <$> C.getLine

gets = fmap (C.filter isPunctuation) . C.lines <$> C.getContents

put = putStrLn . bool "No" "Yes"

sol [n,m] ss = f (n-m) (take n ss) (drop n ss)

f k as bs = or [and $ zipWith C.isPrefixOf bs (C.drop j <$> drop i as) | i <- [0..k], j <- [0..k]]
