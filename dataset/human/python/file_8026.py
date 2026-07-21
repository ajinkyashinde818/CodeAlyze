import Control.Applicative
import qualified Data.Vector.Unboxed as UV

main :: IO ()
main = do
    [k, s] <- map read . words <$> getLine
    let xs = UV.fromList ([0..k] :: [Int])
    print $ UV.foldr (\x xc -> xc + UV.foldr (\y yc -> if 0 <= s - x - y && s - x - y <= k then yc + (1 :: Int) else yc) 0 xs) 0 xs
