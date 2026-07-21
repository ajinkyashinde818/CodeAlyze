import qualified Data.ByteString.Char8 as B
import Data.Char
import Data.Ratio
import Data.Bits
import Control.Monad

toTuple :: B.ByteString -> (Int, Int)
toTuple bs =
    let
        Just (a, bs') = B.readInt bs
        Just (b, _) = B.readInt $ B.dropWhile isSpace bs'
    in
        (a, b)

toBit :: Int -> Int -> [Int]
toBit n l 
    | l == 0 = [] 
    | otherwise = toBit (shiftR n 1) (l - 1) ++ [n .&. 1]

solve :: Int -> [(Int, Int)] -> Int -> Int
solve len pcs goal = minimum $ map step [0..(2^len)-1]
    where
        step :: Int -> Int
        step bit = 
                    case compare r 0 of 
                        LT -> n
                        EQ -> n
                        GT -> 
                            case null fs of
                                True -> 10^9
                                False -> 
                                    let 
                                        ((i,_),(p',_)) = last fs
                                        need = ceiling $ r % (i * 100)
                                    in
                                        case compare need p' of
                                            LT -> n + need
                                            EQ -> 10^9
                                            GT -> 10^9
            where
                zs = zip (zip [1..len] (toBit bit len)) pcs
                (n,r) = foldl inner (0, goal) zs
                inner (acc, rest) ((i,b),(p,c))
                    | b == 1 = (acc + p, rest - (i * 100 * p + c))
                    | otherwise = (acc, rest)
                fs = filter (\((_,b), (_,_)) -> b == 0) zs

main = do
    [d,g] <- map read . words <$> getLine :: IO [Int]
    pcs <- replicateM d (toTuple <$> B.getLine)
    print $ solve d pcs g
