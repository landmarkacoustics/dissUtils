make.example.data <- function(N = 250,
                              n.groups = 5,
                              scale.k = 12,
                              p.count = 20){

    fake.data <- data.frame(ID=factor(sample(1:n.groups, N, replace = T)));

    fake.data$radius <- runif(nrow(fake.data), 0, 1);

    fake.data$angle <- as.numeric(fake.data$ID) * pi / n.groups;

    fake.data$X <- scale.k*fake.data$radius * cos(fake.data$angle) + rnorm(N);

    fake.data$Y <- scale.k*fake.data$radius * sin(fake.data$angle) + rnorm(N);

    return(invisible(fake.data));
}

make.density.data <- function(Y, ids, p){

    Y <- as.matrix(Y);

    ids <- as.factor(ids);

    n.groups <- nlevels(ids);

    require(dissUtils);

    hoops <- data.frame(ID = factor(levels(ids)),
                        p = rep(p,n.groups),
                        delta = numeric(n.groups),
                        ix = integer(n.groups),
                        X = numeric(n.groups),
                        Y = numeric(n.groups));

    dense <- density.by.group(Y, ids, p.neighbors = p);

    tmp <- apply(scale(dense,
                       rep(0,ncol(dense)),
                       apply(dense,2,sum)),
                 1,
                 mean);

    mix <- match(max(tmp),tmp);

    all.ix <- 1:nrow(Y);

    for(j in 1:nlevels(ids)){

        lvl <- levels(ids)[j];

        f <- ids == lvl;

        tmp <- diss(matrix(Y[mix,],nrow = 1),
                    Y[f,]);

        hoops$delta[j] <- min(tmp);

        ix <- match(hoops$delta[j], tmp);

        hoops$ix[j] <- all.ix[f][ix];

        hoops[j,5:6] <- Y[f,][ix,];
    }

    return(invisible(hoops));
}

## temp <- aggregate(hoops$delta, list(ID = hoops$ID), median)

## dev.new(title="changes");

## plot(0, 0, type = 'n',
##      xlab = "p.neighbors",
##      ylab = "distance to densest point",
##      xlim = c(0,1),
##      ylim = range(hoops$delta));

## for(j in 1:5){
##     f <- hoops$ID == j;
##     points(delta ~ p, hoops[f,], type = 'o', col = rainbow(5)[j]);
## }

## abline(h = temp$x, col = rainbow(5), lty = 3);

## dev.new(title="scatter");

## plot(Y ~ X,
##      fake.data,
##      col = rainbow(5)[ID],
##      asp = 1);

## points(Y ~ X,
##        hoops[hoops$delta == 0,],
##        col = rainbow(5)[ID], pch = 16)

## angles <- unique(fake.data$angle);

## segments(rep(0,length(angles)),
##          rep(0,length(angles)),
##          scale.k * cos(angles),
##          scale.k * sin(angles),
##          col = rainbow(5));

