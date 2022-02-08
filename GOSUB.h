#define MAX_STRING 50

//GOSUB is considered as calling a function with a
//chance to return to the function it was called from

// ------ GOSUB 3910 ------
//maneuverEnergy
void maneuverEnergy(int currentEnergy, int energyToWarp){
    currentEnergy = currentEnergy - energyToWarp - 10;
    if (currentEnergy >= 0){
        return;
    }
}
/**/

// ------ GOSUB 6000 ------
/*//shootKlingons
void shootKlingons(int localKlingons,int klingonData[3][3],int sector1,int sector2,int currentShield,int starBaseShieldTf,int shipDamageArray[9],char shipPartName){
    int enemyHit;
    double tempRand;

    if (localKlingons <= 0){
        return;
    }
    if (starBaseShieldTf != 0)
    {
        printf("STARBASE SHEILDS PROTECT THE ENTERPRISE \n");
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        if (klingonData[i][3] <= 0){
            return;
        }
        tempRand = RndZeroToOne();
        enemyHit = floor((klingonData[i][3]/phaserDamageMod(klingonData, sector1, sector2, i))*(2+tempRand));
        currentShield = currentShield - enemyHit;
        klingonData[i][3] = klingonData[i][3]/(3*tempRand);

        printf("%d UNIT HIT ON ENTERPRISE FROM SECTOR %d, %d \n", klingonData[i][1], klingonData[i][2]);
        if (currentShield <= 0)
        {
            //6240
        }
        printf("\t\t\t <SHIELDS DOWN TO %d UNITS \n", currentShield);
        if (enemyHit < 20){
            return;
        }
        if ((RndZeroToOne()>0.6) || ((enemyHit/currentShield) <= 0.02)){
            return;
        }
        int rComponent = RndIntOneToEight();
        shipDamageArray[rComponent] =  shipDamageArray[rComponent]-enemyHit/currentShield-0.5*RndZeroToOne();
        //GOSUB 8790
        printDeviceName(rComponent);
        printf("DAMAGE CONTROL REPORTS %c DAMAGED BY THE HIT \n", shipPartName);
    }
    return;
}
/**/

// ------ GOSUB 6430 Part 1------
/*//shipPreDocking
void shipPreDocking(){
    int i, j;
    for (i = sector1 - 1; i <= sector1 + 1; i++){
        for (j = sector2 - 1; j <= sector2 + 1; j++){
            if ( !((floor(i + 0.5) < 1) || (floor(i + 0.5) > 8) || (floor(j + 0.5) < 1) || ((floor(j + 0.5) > 8))))
            {
                tempObject = ">B<";
                tempObjectPos1 = i;
                tempObjectPos2 = j;
                goSub8830(tempObjectPos1, tempObjectPos2); //GOSUB 8830
                if (mapComparisonTf = 1){
                    return;
                }
            }
        }
    }
    starBaseShieldTf = 0;
    dangerDockingTf = 1;
    return
}
/**/

// ------ GOSUB 6430 Part 2------
/*//shipDocking
void shipDocking(){
    bool skipStatusTf = 0;

    if (dangerDockingTf != 1){
        starBaseShieldTf = 1;
        shipCondition = "DOCKED";
        currentEnergy = maxEnergy;
        currentTorpedos = maxTorpedos;

        printf("SHIELDS DROPPED FOR DOCKING PURPOSES \n");
        currentShield = 0;
        skipStatusTf = 1;
    }
    dangerDockingTf = 0;


    if ((localKlingons > 0)&&(skipStatus !=1)){
        shipCondition = "*RED*";
        //GOTO 6720
    }
    if (skipStatus !=1){
        shipCondition  = "GREEN";
    }
    if ((currentEnergy < maxEnergy*0.1)&&(skipStatusTf !=1)){
        shipCondition = "YELLOW";
    }

    skipStatusTf = 0;
    if ( !(shipDamageArray[2] >=0)){
        printf("\n");
        printf("*** SHORT RANGE SENSORS ARE OUT ***\n");
        printf("\n");
        return;
    }

    spacingText = "---------------------------------" ;
    printf("%c\n", spacingText);
    for (i =1; i <= 8; i++)
    {
        for (j = ((i-1)*24+1), j <=  ((i-1)*24+22), j+= 3)
        {
            printf(" %s", parseMid(quadrantMap, j, 3));  //PRINT " ";MID$(Q$,J,3);
        }
        switch (i)
        {
            case 1:
                printf("        STARDATE           %d", (int) (startStardate*10)*0.01);
                printf("%c", spacingText);
                break;
            case 2:
                printf("        CONDITION          %s", shipCondition );
                printf("%c", spacingText);
                break;
            case 3:
                printf("        QUADRANT           %d, %d", quadrant1, quadrant2);
                printf("%c", spacingText);
                break;
            case 4:
                printf("        SECTOR             %d, %d", sector1, sector2);
                printf("%c", spacingText);
                break;
            case 5:
                printf("        PHOTON TORPEDOES   %d", (int) currentTorpedos);
                printf("%c", spacingText);
                break;
            case 6:
                printf("        TOTAL ENERGY   %d", (int) currentEnergy+currentShield);
                printf("%c", spacingText);
                break;
            case 7:
                printf("        SHIELDS            %d", (int) currentShield);
                printf("%c", spacingText);
                break;
            case 8:
                printf("        KLINGONS REMAINING            %d", (int) totalKlingon);
        }
    }
    printf("%s\n", spacingText);
    return;
}
/**/

// ------ GOSUB 8590 ------
//emptyPlaceQuad
void emptyPlaceQuad(char tempObject[MAX_STRING], int *tempObjectPos1, int *tempObjectPos2){
    int randomInt1 = RndIntOneToEight();
    int randomInt2 = RndIntOneToEight();
    strcpy(tempObject,"   ");
    *tempObjectPos1 = randomInt1;
    *tempObjectPos2 = randomInt2;

    return;
}
/**/

// ------ GOSUB 8670 ------
//enterStringQuad
void enterStringQuad(char tempObject,int tempObjectPos1, int tempObjectPos2, char quadrantMap, int objectLocation, char shipCondition){
    objectLocation = floor(tempObjectPos2-0.5)*3 + floor(tempObjectPos1-0.5)*24+1;

    if(strlen(tempObject) != 3){
        printf("ERROR\n");
        //STOP
    }
    if (objectLocation == 1){
        //shipCondition = tempObject+ parseRIGHT(quadrantMap, 189);//RIGHT$(quadrantMap, 189);
        //still needs work;
        strcpy(shipCondition,tempObject);
        return;
    }
    if (objectLocation == 190){
//      shipCondition = parseLEFT(quadrantMap) + tempObject;//LEFT$(quadrantMap)+tempObject;
        return;
    }
//  shipCondition = parseLEFT(quadrantMap, objectLocation-1)+tempObject + parseRIGHT(quadrantMap, 190 - objectLocation); //LEFT$(quadrantMap, objectLocation-1)+tempObject + RIGHT$(quadrantMap, 190 - objectLocation);
    return;
}
/**/

// ------ GOSUB 8790 ------
//printDeviceName
void printDeviceName(int shipPartInt, char shipPartName[MAX_STRING]){
    //ON R1 GOTO 8792,8794,8796,8798,8800,8802,8804,8806
    switch (shipPartInt){
    case 1: //8792
        strcpy(shipPartName,"WARP ENGINES");
        return;
    case 2: //8794
        strcpy(shipPartName,"SHORT RANGE SENSORS");
        return;
    case 3: //8796
        strcpy(shipPartName,"LONG RANGE SENSORS");
        return;
    case 4: //9798
        strcpy(shipPartName,"PHASER CONTROL");
        return;
    case 5: //8800
        strcpy(shipPartName,"PHOTON TUBES");
        return;
    case 6: //8802
        strcpy(shipPartName,"DAMAGE CONTROL");
        return;
    case 7: //8804
        strcpy(shipPartName,"SHIELD CONTROL");
        return;
    case 8: //8806
        strcpy(shipPartName,"LIBRARY-COMPUTER");
        return;
    }
    return;
}
/**/

// ------ GOSUB 8830 ------
//compareStringInArray
void compareStringInArray(char tempObject[MAX_STRING], int tempObjectPos1, int tempObjectPos2, int objectLocation, bool mapComparisonTf, char quadrantMap){
    //BLOCK 30
    tempObjectPos1 = floor(tempObjectPos1 + 0.5);
    tempObjectPos2 = floor(tempObjectPos2 + 0.5);
    objectLocation = (tempObjectPos2 - 1)*3+(tempObjectPos1 - 1)*24+1;
    mapComparisonTf = 0;

    if (parseMID(quadrantMap, objectLocation, 3) != tempObject){ //MID$(quadrantMap, objectLocation,3)
        return;
    }
    mapComparisonTf = 1;
    return;

}
/**/

// ------ GOSUB 9030 ------
//quadrantNameInArray
void quadrantNameInArray(int quadrantName1, int quadrantName2, char quadrantNameString[MAX_STRING], bool noNumberNamesTf){
    //ON Z4 GOTO 9040,9050,9060,9070,9080,9090,9100,9110
    bool gotoSwitch9210 = 0;
    if (quadrantName2 <= 4){
            switch (quadrantName1){
                case 1:
                    strcpy(quadrantNameString,"ANTARES");
                    gotoSwitch9210 = 1;//GOTO 9210
                    break;
                case 2:
                    strcpy(quadrantNameString,"RIGEL");
                    gotoSwitch9210 = 1;//GOTO 9210
                    break;
                case 3:
                    strcpy(quadrantNameString,"PROCYON");
                    gotoSwitch9210 = 1;//GOTO 9210
                    break;
                case 4:
                    strcpy(quadrantNameString,"VEGA");
                    gotoSwitch9210 = 1;//GOTO 9210
                    break;
                case 5:
                    strcpy(quadrantNameString,"CANOPUS");
                    gotoSwitch9210 = 1;//GOTO 9210
                    break;
                case 6:
                    strcpy(quadrantNameString,"ALTAIR");
                    gotoSwitch9210 = 1;//GOTO 9210
                    break;
                case 7:
                    strcpy(quadrantNameString,"SAGITTARIUS");
                    gotoSwitch9210 = 1;//GOTO 9210
                    break;
                case 8:
                    strcpy(quadrantNameString,"POLLUX");
                    gotoSwitch9210 = 1;//GOTO 9210
            }
    }
//9120
    if (gotoSwitch9210 !=1){ //ON quadrantName1 GOTO 9130,9140,9150,9160,9170,9180,9190,9200
        switch(quadrantName1){
            case 1:
                strcpy(quadrantNameString,"SIRIUS");
                break;//GOTO 9210
            case 2:
                strcpy(quadrantNameString,"DENEB");
                break;//GOTO 9210
            case 3:
                strcpy(quadrantNameString,"CAPELLA");
                break;//GOTO 9210
            case 4:
                strcpy(quadrantNameString,"BETELGEUSE");
                break;//GOTO 9210
            case 5:
                strcpy(quadrantNameString,"ALDEBARAN");
                break;//GOTO 9210
            case 6:
                strcpy(quadrantNameString,"REGULUS");
                break;//GOTO 9210
            case 7:
                strcpy(quadrantNameString,"ARCTURUS");
                break;//GOTO 9210
            case 8:
                strcpy(quadrantNameString,"SPICA");
        }
    }
    gotoSwitch9210 = 0;
//9210
    if (noNumberNamesTf != 1){ //IF G5<>1 THEN ON quadrantName2 GOTO 9230,9240,9250,9260,9230,9240,9250,9260
              switch (quadrantName2){
                case 1:
                    //quadrantNameString = quadrantNameString + ' I';
                    strcat(quadrantNameString, " I");
                    return;
                case 2:
                    //quadrantNameString = quadrantNameString + ' II';
                    strcat(quadrantNameString, " II");
                    return;
                case 3:
                    //quadrantNameString = quadrantNameString + ' III';
                    strcat(quadrantNameString, " III");
                    return;
                case 4:
                     //quadrantNameString = quadrantNameString + ' IV';
                    strcat(quadrantNameString, " IV");
                    return;
                case 5:
                    //quadrantNameString = quadrantNameString + ' I';
                    strcat(quadrantNameString, " I");
                    return;
                case 6:
                    //quadrantNameString = quadrantNameString + ' II';
                    strcat(quadrantNameString, " II");
                    return;
                case 7:
                    //squadrantNameString = quadrantNameString + ' III';
                    strcat(quadrantNameString, " III");
                    return;
                case 8:
                    //quadrantNameString = quadrantNameString + ' IV';
                    strcat(quadrantNameString, " IV");
                    return;
            }
        return;
    }
    return;
}
/**/
