import Data.List
import qualified Data.Sequence as Seq
import Data.Foldable

data Query = QueryReverse | QueryPrepend Char | QueryAppend Char deriving Eq

convertToQueryData :: [String] -> Query
convertToQueryData [_] = QueryReverse
convertToQueryData (_:f:c:_) = if (read f :: Integer) == 1 then QueryPrepend $ head c
  else QueryAppend $ head c

applyQuery :: (Seq.Seq Char, Bool) -> Query -> (Seq.Seq Char, Bool)
applyQuery (xs, isReversed) QueryReverse = (xs, not isReversed) --Seq.reverse xs
applyQuery (xs, False) (QueryPrepend c) = (c Seq.<| xs, False)
applyQuery (xs, True) (QueryPrepend c) = (xs Seq.|> c, True)
applyQuery (xs, False) (QueryAppend c) = (xs Seq.|> c, False)
applyQuery (xs, True) (QueryAppend c) = (c Seq.<| xs, True)

main :: IO ()
main = do
  line <- getLine
  let lineSeq = Seq.fromList line
  nQueriesStr <- getLine
  let nQueries = read nQueriesStr
  stringQueries <- sequence $ take nQueries $ repeat getLine
  let queries = map (convertToQueryData . words) stringQueries
  let (finalList, isReversed) = (foldl' (\ac query -> applyQuery ac query) (lineSeq, False) queries)
  putStrLn (toList (if isReversed then Seq.reverse finalList else finalList))
