angle.example <- function(iterations,
                          sigma.ratio,
                          matrix.size,
                          angle.choices,
                          neighbor.values){

    old.seed <- NULL;

    if(exists(".Random.seed")){
        old.seed <- .Random.seed;
    }

    set.seed(42);


    n.a <- length(angle.choices);
    n.n <- length(neighbor.values);

    aX <- mvrnorm(matrix.size,
                  c(0,0),
                  matrix(c(1,0,0,sigma.ratio),
                         nrow = 2));

    angles <- data.frame(instance = gl(iterations * n.a, n.n),
                         angle = rep(angle.choices,
                                     each = iterations * n.n),
                         neighbors = rep(neighbor.values,
                                         iterations * n.a)
                         );

    for(i in levels(angles$instance)){

        ix <- (as.numeric(i) - 1)*n.n + 1:n.n;

        theta <- angles$angle[ix][1];

        rmat <- matrix(c(cos(theta),
                         sin(theta),
                         sin(theta),
                         -cos(theta)),
                       nrow = 2);

        aY <- aX %*% rmat;

        tmp <- as.matrix(rbind(aX,aY));

        for(j in 1:n.n){
            angles$correlation[ix][j] <- cor(draccaj(tmp,
                                                     rep(1:2,each = 100),
                                                     n.neighbors = angles$neighbors[ix][j]))[2];
        }
    }

    if(!is.null(old.seed)){
        .Random.seed <- old.seed;
    }

    return(invisible(angles));
}
