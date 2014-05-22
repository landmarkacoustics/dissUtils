\name{neighbors}
\alias{neighbors}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
  Find Nearest Neighbor Distances
}
\description{
  Given one (or two) multivariate data sets, a difference method, and k
  neighbors to search for, \code{neighbors} finds the k points in the
  data set (or the second data set) that are closest to each point in
  the data set (or the first data set)
}
\usage{
neighbors(X, Y = NULL, method = "euclidean", n.neighbors = 1, init.info = NULL)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{X}{
    a matrix of numeric values
  }
  \item{Y}{
    an optional second matrix that must have the same number of columns
    as \code{X}
  }
  \item{method}{
    one of the method choices from \code{\link{diss}}
  }
  \item{n.neighbors}{
    an integer between 1 and nrow(X) (or nrow(Y), if it is not null)
  }
  \item{init.info}{
    some difference methods require additional information. see
    \code{\link{diss}}
  }
}
\details{
}
\value{
  returns an \code{nrow(X)} by \code{n.neighbors} matrix of distances
}
\references{
%% ~put references to the literature/web site here ~
}
\author{
  Benjamin Taft \email{taftb@uwp.edu}
}
\note{
%%  ~~further notes~~
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
%% ~~objects to See Also as \code{\link{help}}, ~~~
}
\examples{
##---- Should be DIRECTLY executable !! ----
##-- ==>  Define data, use random,
##--	or do  help(data=index)  for the standard data sets.

## The function is currently defined as
function (X, Y = NULL, method = "euclidean", n.neighbors = 1,
    init.info = NULL)
{
    if (!(is.matrix(X) || (length(dim(X)) == 2)))
        stop("X must be a matrix or matrix-coercible argument")
    if (!(is.null(Y) || is.matrix(Y) || (length(dim(Y)) == 2)))
        stop("Y must be NULL or a matrix or matrix-coercible object")
    method = match.arg(method, ..known.methods)
    if (is.null(Y)) {
        if (method == "mahalanobis")
            init.info <- .make.s.prime(X)
        return(invisible(matrix(.C("neighbors", as.double(X),
            as.integer(dim(X)), as.character(method), as.double(init.info),
            as.integer(length(init.info)), as.integer(n.neighbors),
            oot = double(nrow(X) * n.neighbors), DUP = TRUE)$oot,
            nrow = nrow(X), byrow = T, dimnames = list(rownames(X),
                paste("neighbor", 1:n.neighbors, sep = ".")))))
    }
    else if (ncol(X) == ncol(Y)) {
        if (method == "mahalanobis")
            init.info <- .make.s.prime(rbind(X, Y))
        return(invisible(matrix(.C("two_matrix_neighbors", as.double(X),
            as.integer(dim(X)), as.double(Y), as.integer(dim(Y)),
            as.character(method), as.double(init.info), as.integer(length(init.info)),
            as.integer(n.neighbors), oot = double(nrow(X) * n.neighbors),
            DUP = TRUE)$oot, nrow = nrow(X), byrow = T, dimnames = list(rownames(X),
            paste("neighbor", 1:n.neighbors, sep = ".")))))
    }
    return(NULL)
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ ~kwd1 }
\keyword{ ~kwd2 }% __ONLY ONE__ keyword per line
