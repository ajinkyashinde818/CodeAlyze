import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as Map
import Data.Array
import qualified Data.ByteString.Char8 as BC
import Data.Maybe
import qualified Data.Set as Set
import qualified Data.Sequence as Sq
import qualified Data.IntMap as IMap
import qualified Data.Vector as V
import Data.Sequence (ViewL(..),ViewR(..),(><),(<|),(|>),Seq)

bsreadInt :: BC.ByteString -> Int
bsreadInt = fst . fromJust . BC.readInt

sqleft :: Seq a -> a
sqleft q = sqleft_(Sq.viewl q)
sqleft_ :: ViewL a -> a
sqleft_ (x :< xs) = x
sqright :: Seq a -> a
sqright q = sqright_(Sq.viewr q)
sqright_ :: ViewR a -> a
sqright_ (xs :> x) = x
-------------------------------------------------------------
main = do
    s <- getLine
    let ss = sort s
    if (ss == "abc")
    then putStrLn "Yes"
    else putStrLn "No"
