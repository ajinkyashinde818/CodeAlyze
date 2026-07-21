import Control.Applicative
import Control.Monad
import System.IO.Unsafe
import Control.Monad.ST
import Data.Functor
import Data.Function
import Data.Monoid
import Data.Maybe
import Data.List
import Data.Foldable (foldMap)
import Data.List.Split
import Data.Bits
import Data.Char
import Data.Ix
import Data.Ratio
import Data.Ord
import Data.Tuple
import Data.Array
import Data.Array.IO
import Data.Array.ST
import Data.IORef
import Data.STRef
 
readInt = read :: String -> Int
readDouble = read :: String -> Double
getInt = readLn :: IO Int
getInts = map readInt . words <$> getLine
getDouble = readLn :: IO Double
sjoin :: (Show a) => [a] -> String
sjoin = unwords . map show
cond :: a -> a -> Bool -> a
cond t f c = if c then t else f
apply2 :: (a -> a -> b) -> [a] -> b
apply2 f [x,y] = f x y
apply3 :: (a -> a -> a -> b) -> [a] -> b
apply3 f [x,y,z] = f x y z
fnBin :: (b -> c -> d) -> (a -> b) -> (a -> c) -> a -> d
fnBin op f g x = op (f x) $ g x
fnTuple :: (a -> b, a -> c) -> a -> (b, c)
fnTuple (f,g) a = (f a, g a)
replace :: (Eq a) => a -> a -> [a] -> [a]
replace x y = map (\z -> if z==x then y else z)
modifyArray :: (Ix i, MArray a e m) => a i e -> i -> (e -> e) -> m ()
modifyArray arr ix f = readArray arr ix >>= writeArray arr ix . f
-- end of templete


main = do
    s <- sort <$> getLine
    t <- sortBy (flip compare) <$> getLine
    putStrLn $ cond "Yes" "No" $ s < t
