import Data.Char
import Data.List
import qualified Data.ByteString.Char8 as B
import qualified Data.Vector.Unboxed as V
main=print.solve.V.unfoldr(B.readInt.B.dropWhile isSpace)=<<(B.getLine>>B.getLine)
solve=g=<<V.foldr f(0,0,0)
f a(i,j,k)
  |a<0=(i+1,j,k)
  |a>0=(i,j,k+1)
  |otherwise=(i,j+1,k)
g(i,j,k)as
  |even i || j>0=V.sum bs
  |otherwise=V.sum bs-V.minimum bs*2
  where bs=V.map abs as
