import Control.Applicative
import Control.Monad
import Control.Monad.ST
import Data.Functor
import Data.Function
import Data.Monoid
import Data.Maybe
import Data.List
import Data.Foldable (foldMap)
import Data.List.Split
import Data.Char
import Data.Ratio
import Data.Ord
import Data.Tuple
import Data.Array.IO
import Data.Array.ST
import Data.IORef
import Data.STRef
 
readInt = read :: String -> Int
readDouble = read :: String -> Double
getInt = readLn :: IO Int
getInts = map readInt . words <$> getLine
sjoin :: (Show a) => [a] -> String
sjoin = unwords . map show
cond :: a -> a -> Bool -> a
cond t f c = if c then t else f
applyBin :: (b -> c -> d) -> (a -> b) -> (a -> c) -> a -> d
applyBin op f g x = op (f x) $ g x
applyUni :: (a -> b -> c) -> (a -> b) -> a -> c
applyUni op f x = op x $ f x
applyTuple :: (a -> b, a -> c) -> a -> (b, c)
applyTuple (f,g) a = (f a, g a)
-- end of templete

rotate n = applyBin (++) (drop n) (take n)

list = [4,1,4,1,2,1,2,1]

f s = minimumBy (\x y -> comparing remain x y <> compare x y) $ flip map [0..7] $ \i -> rotate i list
  where
    remain = sum . zipWith ((max 0 .)  . (-)) s


main = map (unwords . map show . f . map read . words) . lines <$> getContents >>= mapM_ putStrLn
