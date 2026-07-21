import Data.Char
import qualified Data.Map.Strict as M
import Data.Map.Strict ((!))

main = putStrLn . (results!) . (\[l,r] -> compare l r) . map digitToInt . filter isHexDigit =<< getLine

results = M.fromDistinctAscList [(LT,"<"), (EQ,"="), (GT,">")]
