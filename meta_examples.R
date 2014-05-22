source("~/Source/Projects/R/dissUtils/examples.R");

extract <- function(X,nom){as.numeric(t(sapply(X, function(x){x[[nom]]})))};

whole.hoops <- list();
whole.data <- list();

for(lab in c(letters,LETTERS)){

    fake.data <- make.example.data();

    hoops <- make.density.data(fake.data[,4:5],
                               fake.data$ID,
                               1);

    for(i in (p.count-1):1){

        temp <- make.density.data(fake.data[,4:5], fake.data$ID, i / p.count);

        hoops <- rbind(temp, hoops);
    }

    whole.hoops[[lab]] <- hoops;

    whole.data[[lab]] <- fake.data;
}


all.data <- data.frame(ID = factor(extract(whole.data, "ID")));

for(n in names(whole.data$A)[-1]){

    all.data[[n]] <- extract(whole.data, n);
}

all.data$ID <- factor(all.data$ID);

all.densest <- data.frame(ID = factor(extract(whole.hoops, "ID")));

for(n in names(whole.hoops$A)[-1]){

    all.densest[[n]] <- extract(whole.hoops, n);
}

temp <- aggregate(all.densest$delta, as.list(all.densest[,1:2]), mean);

temp$sd <- aggregate(all.densest$delta, as.list(all.densest[,1:2]), sd)$x;

temp$N <- aggregate(all.densest$delta, as.list(all.densest[,1:2]), length)$x;

temp$lo <- temp$x - temp$sd / sqrt(temp$N);

temp$hi <- temp$x + temp$sd / sqrt(temp$N);


png("all scatter.png",
    width = 8, height = 8,
    units = "in", res = 90, pointsize = 12,
    bg = "black");

par(mar = c(10,10,2,2)/3,
    mgp = 2 * c(3,1,0)/3,
    bg = "black",
    fg = "white", col.axis = "white", col.lab = "white");

plot(Y ~ X, all.data, pch ='.', col = rainbow(5,alpha = 2/3)[ID], asp = 1);

points(Y~X, all.densest, cex = 1/2, col = rainbow(5)[ID]);

pdf("all trends.pdf", 8, 8, useDingbats = F)

par(mar = c(10,10,2,2)/3, mgp = 2 * c(3,1,0)/3)

plot(1,10, type = 'n',
     xlab = "proportion of neighbors examined",
     ylab = "distance to group densest point",
     xlim = c(0,1),
     ylim = range(temp[,6:7]),
     log = 'y');

for(j in 1:5){

    f <- temp$ID == j;

    segments(temp$p[f], temp$lo[f],
             temp$p[f], temp$hi[f],
             col = rainbow(5)[j]);

    points(x ~ p, temp[f,], col = rainbow(5)[j], type = 'o');
}
