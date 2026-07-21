{-#LANGUAGE FlexibleContexts#-}
import Control.Monad
import Control.Monad.State
import Control.Monad.Reader
import Control.Arrow
-- import Control.Comonad
import Data.Maybe
import Data.List
import Data.Bool
import Data.Fixed
import Data.Tuple
import Data.Ratio
import qualified Data.Map.Strict as M
import qualified Data.Array.IO as IA
import qualified Data.Vector as V

getI = read <$> getLine :: IO Int
getIs = map read . words <$> getLine :: IO [Int]
getD = read <$> getLine :: IO Double
getDs = map read . words <$> getLine :: IO [Double]
getInt = read <$> getLine :: IO Integer
getInts = map read . words <$> getLine :: IO [Integer]

type Row = Integer
type Col = Integer
type PointI = (Integer, Integer)
type Point = (Int, Int)

mmm = 1000000007
fact n
    | n < 1 = 1
    | True = foldr1 (*) [1..n]
ti = toInteger
fi = fromInteger
fig = fromIntegral
rf = realToFrac

(.<.) :: Integer -> Integer -> Integer
(.<.) f g -- combination
    | g < 1 || f < 1 || f < g = 1
    | True = foldr1 (*) (take (fi g) [f,f-1..]) `div` fact g
(.>.) f g --combination with repetition
    | g < 1 || f < 1 = 1
    | True = fact (f + g - 1) `div` (fact (f - 1) * fact g)
comb = (.<.)
combWp = (.>.)

unique a = unique_ (reverse . sort $ a) [] Nothing
    where
        unique_ [] arr _ = arr
        unique_ (x:xs) arr n
            | n == Just x = unique_ xs arr n
            | otherwise = unique_ xs (x:arr) $ Just x
 
zeroume keta num
    | (length . show $ num) > keta = show num
    | otherwise = do 
        let zeros = take keta $ repeat '0'
        reverse . take keta $ (reverse . show $ num) ++ zeros
 
i2b num
    | num < 2 = show num
    | otherwise = i2b_ num []
        where
            i2b_ num str
                | num == 0 = str
                | num == 1 = '1':str
                | otherwise = do
                    let next = num `div` 2
                    let this = if odd num then '1' else '0'
                    i2b_ next (this:str)

mapIncr = mapPlus 1
mapPlus n Nothing = Just n
mapPlus n a = (+) n <$> a

countIf f = length . filter f

enumDivisor :: Int -> [Int]
enumDivisor n = do
    let sqrted = floor $ sqrt (fromIntegral n)
        smaller = filter (\x -> mod n x == 0) [1..sqrted]
        bigger = reverse $ map (div n) smaller
    if head bigger == sqrted then smaller ++ (init bigger)
    else smaller ++ bigger

safeHead [] = Nothing
safeHead (x:_) = Just x

-- 
--
--

main = do
    [a,b,c] <- getIs
    putStrLn . show $ b + min c (a + b + 1)
