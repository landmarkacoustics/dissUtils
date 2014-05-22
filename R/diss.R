diss <- function(X, Y = NULL,
                 method = "euclidean",
                 init.info = NULL){

    if(! (is.matrix(X) || ( length(dim(X)) == 2) ) )
        stop("X must be a matrix or matrix-coercible argument");

    if( ! (is.null(Y) || is.matrix(Y) || ( length(dim(Y)) == 2) ) )
        stop("Y must be NULL or a matrix or matrix-coercible object");

    # this will throw an error if "method" is not a character vector in knownmethods
    method = match.arg(method, .known.methods);

    if(is.null(Y)) {

        if(method == "mahalanobis")
            init.info <- .make.s.prime(X);

        tmp <- .C("differences",
                  as.double(X),
                  as.integer(dim(X)),
                  as.character(method),
                  as.double(init.info),
                  as.integer(length(init.info)),
                  oot = double( nrow(X) * (nrow(X) - 1) / 2),
                  DUP = TRUE)$oot;

        attributes(tmp) <- list( Size = nrow(X),
                                 Labels = rownames(X),
                                 Diag = F, Upper = F,
                                 method = method );

        class(tmp) <- c("diff", "dist", class(tmp));

        return(invisible(tmp));
    }
    else if(ncol(X) == ncol(Y)){

        if(method == "mahalanobis")
            init.info <- .make.s.prime(rbind(X,Y));

        return( invisible( matrix(
                                  .C("two_matrix_differences",
                                     as.double(X),
                                     as.integer(dim(X)),
                                     as.double(Y),
                                     as.integer(dim(Y)),
                                     as.character(method),
                                     as.double(init.info),
                                     as.integer(length(init.info)),
                                     oot = double(nrow(X) * nrow(Y) ),
                                     DUP = TRUE)$oot,
                                  nrow = nrow(X),
                                  byrow = T,
                                  dimnames = list(rownames(X),
                                                  rownames(Y))
                                  )));
    }

    return(NULL);
}
