import Data.List

judge :: Bool -> (String,String) -> String
judge f (ts,fs) = case f of
  True -> ts
  False -> fs

func :: Ord a => [a] -> [a] -> Bool
func _ [] = False
func [] _ = True
func (x:xs) (y:ys)
  | x < y = True
  | x > y = False
  | x == y = func xs ys

main = do
  line1 <- getLine
  line2 <- getLine
  let
    ret = func (sort line1) (sortBy (flip compare) line2)
  putStrLn $ judge ret ("Yes","No")
