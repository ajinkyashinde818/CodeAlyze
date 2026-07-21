import Control.Applicative

func x y z k =
  if x>k || y>k || z>k || x<0 || y<0 || z<0 then
    0
  else
    1


main = do
  (k:s:_) <- (map (read::String->Int)) . words <$> getLine

  print $ sum $ map (\x ->
                 sum $ map (\y ->
                        let
                          z = s-x-y
                        in
                          func x y z k
                        )
                 [0..k])
    [0..k]
