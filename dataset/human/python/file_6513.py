import qualified Data.Vector.Unboxed as U
import qualified Data.Vector as V
import qualified Data.ByteString.Char8 as C
import Data.List
import Control.Monad
import Control.Arrow
import qualified Data.IntMap as IM
import qualified Data.IntSet as IS
import Data.Maybe
import qualified Data.Sequence as Seq
import Data.Foldable

r :: Int -> IO (U.Vector Int)
r n = U.unfoldrN n (C.readInt . C.dropWhile (==' ')) <$> C.getLine

r' :: IO [Int]
r'  =   unfoldr    (C.readInt . C.dropWhile (==' ')) <$> C.getLine

data FB = Front | Back deriving Show

qread :: Int -> Bool -> IO [Maybe (FB,Char)]
qread 0 rev = return $ if rev then [Nothing] else []
qread n rev = do
    query <- words <$> getLine
    if read (head query) == 1
        then qread (n-1) (not rev)
        else let ["2",x,c] = query
            in do
                rc <- qread (n-1) rev
                return $ Just (rd (read x,rev),head c):rc

rd (1,False) = Front
rd (2,False) = Back
rd (1,True ) = Back
rd (2,True ) = Front

main :: IO ()
main = do
    s <- getLine
    q <- readLn
    qs <- qread q False
    putStrLn $ toList $ solve qs (Seq.fromList s)

solve :: [Maybe (FB,Char)] -> Seq.Seq Char -> Seq.Seq Char
solve []    sq = sq
solve [Nothing] sq = Seq.reverse sq
solve (Just (Front,c):xs) sq = solve xs (c Seq.<| sq)
solve (Just (Back,c):xs) sq = solve xs (sq Seq.|> c)
