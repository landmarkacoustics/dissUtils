boots0 <- data.frame(iter=1:1000, corr = numeric(1000));

for(i in boots0$iter){

    boots0$corr[i] <- cor(draccaj(tmp0,sample(1:2,200,T),n.neighbors = 20))[2];
}

boots <- data.frame(iter=1:1000, corr = numeric(1000));

for(i in boots$iter){

    boots$corr[i] <- cor(draccaj(tmp,sample(1:2,200,T),n.neighbors = 20))[2];
}

par(mfrow = c(2,1), mar = c(10,10,10,2)/3, mgp = 2 * c(3,1,0)/3)

hist(boots0$corr, breaks = 0:100/100, main = "equal variances")

abline(v=cor(drake0)[2])

hist(boots$corr, breaks = 0:100/100, main = "variance(x) = 10 * variance(y)")

abline(v=cor(drake)[2])
