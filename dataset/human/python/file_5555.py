import           Control.Monad
import qualified Data.Sequence as Seq

main = do
  s <- Seq.fromList <$> getLine

  let solve s res | Seq.length s < 2 = res
                  | otherwise =
                    let l Seq.:< ss = Seq.viewl s
                        ss' Seq.:> r = Seq.viewr ss
                    in
                      if l == r
                      then solve ss' res
                      else case (l, r) of
                        ('x', _) -> solve (s Seq.|> 'x') (res+1)
                        (_, 'x') -> solve ('x' Seq.<| s) (res+1)
                        _        -> -1

  print $ solve s 0
