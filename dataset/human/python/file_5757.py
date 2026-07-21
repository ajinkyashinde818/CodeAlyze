import Data.List
import Data.Char
import Data.Maybe
import qualified Data.ByteString.Char8 as BS8

sol a b c 0 0 = sol (tail a) b c (b !! (head a - 1)) (head a)
sol a b c i j
    | l == 1 && ha == (j+1) = i + ba + ca
    | l == 1                = i + ba
    | ha == (j+1)           = sol ta b c (i + (ba + ca)) ha
    | otherwise             = sol ta b c (i + ba) ha
    where
        l = length a
        ha = head a
        ta = tail a
        ba = b !! (ha-1)
        ca = c !! (ha-2)

main :: IO ()
main = do
    n <- fst . fromJust . BS8.readInteger <$> BS8.getLine
    a <- unfoldr (BS8.readInt . BS8.dropWhile isSpace) <$> BS8.getLine
    b <- unfoldr (BS8.readInt . BS8.dropWhile isSpace) <$> BS8.getLine
    c <- unfoldr (BS8.readInt . BS8.dropWhile isSpace) <$> BS8.getLine

    print $ sol a b c 0 0
