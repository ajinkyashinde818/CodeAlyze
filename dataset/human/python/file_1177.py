import qualified Data.ByteString.Char8 as B
import Data.Maybe
main = print.solve.map(fst.fromJust.B.readInt).B.words=<<B.getContents
solve (_:as) = minimum.map(\x->abs$x+x-s).scanl1(+)$init as where s=sum as
