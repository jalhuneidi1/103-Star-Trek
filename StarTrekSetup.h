void DrawEnterprise(void){

printf("\n\n\n\n\n\n\n\n\n\n\n");
printf("                                    ,------*------,\n");
printf("                    ,-------------   '---  ------'\n");
printf("                     '-------- --'      / /\n");
printf("                         ,---' '-------/ /--,\n");
printf("                          '----------------'\n");
printf("\n");
printf("                    THE USS ENTERPRISE --- NCC-1701\n");
printf("\n\n\n\n\n");

}

void WeaponsStartingValues(int *currentEnergy,int *maxEnergy,int *currentTorpedoes,int *maxTorpedos,int *currentShield,int *starBaseShieldTf,int *klingonShieldMod){

    *starBaseShieldTf=0;
    *currentEnergy=3000;
    *maxEnergy=*currentEnergy;

    *currentTorpedoes=10;
    *maxTorpedos=*currentTorpedoes;

    *klingonShieldMod=200;
    *currentShield=0;
    return;
}

void NavArraySetup(int navArray[10][3])
{//Setup for nav array
    for (int i=0; i<10; ++i) {
        navArray[i][1]=0;
        navArray[i][2]=0;
    }
    navArray[3][1]=-1;
    navArray[2][1]=-1;
    navArray[4][1]=-1;
    navArray[4][2]=-1;
    navArray[5][2]=-1;
    navArray[6][2]=-1;

    navArray[1][2]=1;
    navArray[2][2]=1;
    navArray[6][1]=1;
    navArray[7][1]=1;
    navArray[8][1]=1;
    navArray[8][2]=1;
    navArray[9][2]=1;
    return;
}

void DamageArraySetup(int shipDamageArray[9]){
    for (int i=0; i<9; ++i) {
        shipDamageArray[i]=0;
    }
    return;
}
