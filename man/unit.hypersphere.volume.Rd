\name{unit.hypersphere.volume}
\alias{unit.hypersphere.volume}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
  Helps When Calculating Densities
}
\description{
 Finds the volume of a hypersphere in R^D with radius one.
}
\usage{
unit.hypersphere.volume(D)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{D}{
    the number of dimensions that the hypersphere extends into
  }
}
\details{
%%  ~~ If necessary, more details than the description above ~~
}
\value{
  the volume of the unit hypersphere
}
\references{
  http://en.wikipedia.org/wiki/N-sphere
}
\author{
  Benjamin N. Taft \email{taftb@uwp.edu}
}
\note{
%%  ~~further notes~~
}

%% ~Make other sections like Warning with \section{Warning }{....} ~

\seealso{
%% ~~objects to See Also as \code{\link{help}}, ~~~
}
\examples{
## The function is currently defined as
function (D)
{
    return(exp((D / 2) * log(pi) - log(gamma(1 + D/2))));
  }
}
% Add one or more standard keywords, see file 'KEYWORDS' in the
% R documentation directory.
\keyword{ multivariate }
