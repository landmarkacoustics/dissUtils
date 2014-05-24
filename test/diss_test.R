require(dissUtils);

set.seed(42);

cats <- matrix(runif(18,0,2),6);
dogs <- floor(cats);

approaches <- c("braycurtis",
                "canberra",
                "chebyshev",
                "covariance",
                "euclidean",
                "equality",
                "hellinger",
                "jaccard",
                "jointentropy",
                "mahalanobis",
                "manhattan",
                "minkowski",
                "pearson",
                "procrustes");

for(a in approaches){
    str(diss(cats, method = a));
}
