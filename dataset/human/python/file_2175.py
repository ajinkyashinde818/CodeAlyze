{-# LANGUAGE TupleSections #-}
import Data.List
import qualified Data.ByteString.Char8 as B
import Control.Monad.State (State, evalState, gets, modify)
import Data.Map.Strict (Map, lookup, insert, empty)
import Data.Maybe (maybe)
import Control.Monad
main :: IO ()
main = breads >>= main'
    where
        main' [d, g] = replicateM d breads >>= print . solve g

-- |
-- >>> solve 700 [[3,500],[5,800]]
-- 3
--
-- >>> solve 2000 [[3,500],[5,800]]
-- 7
--
-- >>> solve 400 [[3,500],[5,800]]
-- 2
--
-- >>> solve 25000 [[20,1000],[40,1000],[50,1000],[30,1000],[1,1000]]
-- 66
solve :: Int -> [[Int]] -> Int
solve g pcs = run calc . (g, [],) . map build $ zip pcs [1..]
    where
        build ([p, c], i) = (100 * p * i + c, p, 100 * i)

        calc f (r, ps, (w, c, p) : xs)
            | r > 0 = minimum <$> sequence [(+ c) <$> f (r - w, ps, xs), f (r, (c - 1, p) : ps, xs)]
            | otherwise = return 0
        calc _ (r, ps, _)
            | r > 0 = return . calc2 r . sortBy cmpf $ filter (\(c, _) -> c > 0) ps
            | otherwise = return 0
            where
                cmpf (_, lp) (_, rp) = compare rp lp
        
        calc2 r ((c, p) : xs)
            | r >= cp = c + calc2 (r - cp) xs
            | r > 0 = v
            | otherwise = 0
            where
                cp = c * p
                (a, m) = r `divMod` p
                v
                    | m > 0 = a + 1
                    | otherwise = a
        calc2 r _
            | r > 0 = 100000
            | otherwise = 0


type Memoizer a b = a -> State (Map a b) b

run :: (Ord a) => (Memoizer a b -> Memoizer a b) -> a -> b
run f = flip evalState empty . memoizeFix f

memoizeFix :: (Ord a) => (Memoizer a b -> Memoizer a b) -> Memoizer a b
memoizeFix f x = gets (Data.Map.Strict.lookup x) >>= maybe (f (memoizeFix f) x >>= ((<$) <*> (modify . Data.Map.Strict.insert x))) return

breads :: IO [Int]
breads = unfoldr uff <$> B.getLine
    where
        uff b = check <$> B.readInt b
        check (a, b)
            | B.null b = (a, b)
            | otherwise = (a, B.tail b)
