.make.s.prime <- function(M){

    init.info <- diag(nrow=ncol(M));

    try(init.info <- solve(cov(M)));

    return(init.info);
}

