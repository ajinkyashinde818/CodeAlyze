import Data.Char

solvea :: (Int,Int) -> Int
solvea (a,b) = min a b

solveb ::(Int,Int) -> Int -> (Int,Int)
solveb (a,b) p = (solvea (a+p, b+p), solvea(a+11-p, b+9-p))


{-
example :: (Int,Int) -> Int
example (a,b) = fst (a,b)
-}
--solvec:: string -> Int

solvec xs = foldr (\x (a,b)-> solveb (a,b) $ ssolvec $ x) (0,10) xs
ssolvec::Char -> Int
ssolvec x = digitToInt x

solved = solvea . solvec



--examplec::[Int] -> Int
-- examplec xs = foldr (\x (a,b) -> solveb(a,b) x) (0,10) xs
-- examplecc xs = foldl (\(a,b) x -> solveb(a,b) x) (0,10) xs

main = do
    x <- getLine--xはstring
    -- print $ digitToInt $ head x
    -- print $ examplec [3,6]
    -- print $ examplecc [3,6]
    -- print $ solvec "36"
    -- print $ solved "36"
    print $ solved x
    -- print $ snd f
    -- where f = solveb (2,4) 5
