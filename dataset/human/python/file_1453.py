import Control.Applicative
import Control.Monad
import Data.List
main = getLine >>= main' . map read . words >>= putStrLn
    where
        main' [n, m] = solve (n - m + 1) <$> replicateM n getLine <*> replicateM m getLine

solve :: Int -> [String] -> [String] -> String
solve c as bs
    | res = "Yes"
    | otherwise = "No"
    where
        res = recf c as
        recf 0 _ = False
        recf n xs
            | r = True
            | otherwise = recf (n - 1) $ tail xs
            where
                r = reccolf c xs

        reccolf 0 _ = False
        reccolf n xs
            | r = True
            | otherwise = reccolf (n - 1) $ map tail xs
            where
                r = all ff $ zip bs xs
                ff (b, x) = b `isPrefixOf` x
