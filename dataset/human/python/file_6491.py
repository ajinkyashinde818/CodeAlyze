import           Control.Monad
import           Data.Foldable
import qualified Data.Sequence as S
import           Data.Sequence ( Seq(..), (<|), (|>) )

data Direction = L | R

data Query = Reverse | InsertHead !Char | AppentLast !Char

main :: IO ()
main = do
  s <- S.fromList <$> getLine
  q <- readLn
  qs <- replicateM q readQuery
  putStrLn $ toList $ solve s L qs

solve :: Seq Char -> Direction -> [Query] -> Seq Char
solve s L []                  = s
solve s R []                  = S.reverse s
solve s L (Reverse      : qs) = solve s R qs
solve s R (Reverse      : qs) = solve s L qs
solve s L (InsertHead c : qs) = solve (c <| s) L qs
solve s R (InsertHead c : qs) = solve (s |> c) R qs
solve s L (AppentLast c : qs) = solve (s |> c) L qs
solve s R (AppentLast c : qs) = solve (c <| s) R qs

readQuery :: IO Query
readQuery = do
  q <- getLine
  case map head (words q) of
    ['1']         -> return $ Reverse
    ['2', '1', c] -> return $ InsertHead c
    ['2', '2', c] -> return $ AppentLast c
