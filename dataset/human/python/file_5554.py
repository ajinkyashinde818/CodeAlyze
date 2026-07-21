import Control.Applicative
import Data.Maybe
import qualified Data.Sequence as S
import Data.Sequence (Seq, fromList, (<|), (|>), viewl, viewr, ViewL(..), ViewR(..))
 
main = getLine >>= print . fromMaybe (-1) . solve . fromList
 
solve :: Seq Char -> Maybe Int
solve q
  | S.length q <= 1 = Just 0
  | l == r    = solve ms
  | l == 'x'  = succ <$> solve (q |> 'x')
  | r == 'x'  = succ <$> solve ('x' <| q)
  | otherwise = Nothing
  where
    (l :< rs) = viewl q
    (ms :> r) = viewr rs
