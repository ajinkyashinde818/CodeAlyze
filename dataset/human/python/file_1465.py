import Control.Monad
import Data.List

main=do
    [n,m]<-map read.words<$>getLine
    aan <- replicateM n getLine
    am <- concat<$>replicateM m getLine
    let aam = map (f aan m) [0..(n-m)]
    let cs = concatMap (\aa -> map (\i-> g m i aa) [0..(n-m)]) aam
    putStrLn $ case find (==am) cs of
        Just _ -> "Yes"
        Nothing -> "No"

f aan m i = take m $ drop i aan
g m i = concatMap (take m . drop i)
