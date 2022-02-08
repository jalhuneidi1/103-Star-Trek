int RndIntOneToEight(void)
{//Define usermade function FNR(R) as a random integer between 1 and 8
    time_t t;
    srand((unsigned) time(&t));
    return ((rand()%8)+1);
}

double RndZeroToOne(void)
{//Define usermade function as a random number between 0.00 and 0.99 to two decimal places
    time_t t;
    srand((unsigned) time(&t));
    return ((rand()%100)*0.01);
}

double phaserDamageMod(int klingonData[3][3], int sector1, int sector2, int i)
{//In BASIC this function was FND(D).
    return ((klingonData[i][1] - sector1)^2 + (klingonData[i][2] - sector2)^2);
}
