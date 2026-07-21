import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Data.List
import Data.Char

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

main = do
    [d,g] <- getIntList
    pc <- fmap (zip [1..]) $ replicateM d $ do
        [p,c] <- getIntList
        return (p,c)
    let tfs = sequence $ replicate d [True,False]
    let solve tf = ans
            where solve' tf = foldl' (\(a,b) (a',b') -> (a+a',b+b')) (0,0) $ zipWith f pc tf
                      where f (i,(p,c)) True = (p, i*100*p + c)
                            f _ False = (0,0)
                  (probs,score) = solve' tf
                  m = g - score
                  ans | m <= 0 = (probs,score)
                      | otherwise = (probs+p',score+s')
                              where (i',(pi',_)) = fst . last . filter (not . snd) $ zip pc tf
                                    p' = min pi' $ (m - 1) `div` (i' * 100) + 1
                                    s' = i' * 100 * p'
    let anss = map solve tfs
    print . minimum . map fst $ filter ((g<=) . snd) anss
