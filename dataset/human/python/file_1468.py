import Data.Bool
import Control.Monad
import qualified Data.Vector as V
main=putStrLn.solve.lines=<<getContents
solve(nm:ab)=bool"No""Yes"$any f$replicateM 2[0..n-m]where
  [n,m]=map read.words$nm
  (as,bs)=V.splitAt n.V.fromList.map V.fromList$ab
  f[i,j]=and.V.zipWith(==)bs$V.map(V.slice j m).V.slice i m$as
