import Control.Monad
import Control.Applicative

square x w xn yn = [x+k*yn+l | k<-[0..w-1],l<-[0..w-1]]
main = do
    [an,bn] <- map (read :: String -> Int) . words <$> getLine
    aa <- replicateM an getLine
    bb <- replicateM bn getLine
    let a = concat aa
    let b = concat bb
    
    let snakes = [(a!!) <$> (square x bn an an) | x<-(square 0 (an-bn+1) an an)]
    putStrLn $ if (elem b snakes)
        then "Yes"
        else "No"
