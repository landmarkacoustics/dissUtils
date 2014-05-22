\name{neighbor.density}
\alias{neighbor.density}

\title{
  Calculate Multidimensional Densities from Neighbor Distances
}
\description{
  \code{neighbor.density} estimates the density around a point by
  accounting for the dimensionality of the space the neighbors are in,
  the total number of points in the space, and how many neighbors are
  found at least as close to the point as the density given.
}
\usage{
neighbor.density(neigh.dists, D, k, N)
}

\arguments{
  \item{neigh.dists}{
    a vector of distances between members of a multivariate data set and
    their \code{k}th-nearest neighbor
  }
  \item{D}{
    the number of dimensions of the multivariate space
  }
  \item{k}{
    the number of neighbors found around each point within the
    hyperspheres with radii given in \code{neigh.dists}
  }
  \item{N}{
    the total number of points in the data set from which the neighbors
    are drawn. This may not be equal to \code{length(neigh.dists)} if
    the neighbors are in a separate data set from the points of interest.
  }
}
\value{
  a numeric vector of densities
}
\references{
  http://en.wikipedia.org/wiki/N-sphere
}

\examples{

## The function is currently defined as
function (neigh.dists, D, k, N)
{
    radius <- unit.hypersphere.volume(D)
    return(k/(N * radius * neigh.dists))
  }
}

\keyword{ multivariate }