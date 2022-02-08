/* ------ MID$ ------*/
//function to return a substring from a specific index up to a given length
//print statement in block would look like printf("%s", parseMID(VARIABLE NAME, START INDEX NUMBER, END INDEX NUMBER))
char parseMID(char param[], int startIndex, int length){
    int i;
    char *result;
    result = malloc(length+1);

    for (i = 0; i < length; i++){
        *(result + i) = *(param + startIndex);
        param++;
    }

    *(result + i) = '\0';
    return result; // return substring starting from index given

}

/* ------ RIGHT$ ------*/
//function to return a substring from the right up to the given length
//print statement in block would look like printf("%s", parseRIGHT(VARIABLE NAME, lengthNumber))
char parseRIGHT(char *param, int length){
    int i;
    int j = strlen(param) - 1;
    char *result;
    result = malloc(length + 1);

    for (i = 0; i < length; i++, j--){
        *(result + i) = *(param+j);
        //i++
    }

    *(result + i) = *(param + j);
    return result; //return substring starting from the right
}

/* ------ LEFT$ ------*/
//function to return a substring from the left up to the given length
//print statement in block would look like printf("%s", parseLEFT(VARIABLE NAME, lengthNumber))
char* parseLEFT(char* param, int length){
    int i = 0;
    char *result;
    result = malloc(length+1); //allocate memory for th character array result

    while (i < length){
        *(result + 1) = *(param + i);
        i++;
    }

    *(result + 1) = '\0';
    return result; // return a substring from the left
}


/* ------ GOTO 980 ------*/

/* ------ GOTO 1320 ------*/

/* ------ GOTO 1500 ------*/

/* ------ GOTO 1980 ------*/

/* ------ GOTO 1990 ------*/

/* ------ GOTO 2880 ------*/

/* ------ GOTO 3070 ------*/

/* ------ GOTO 3370 ------*/

/* ------ GOTO 4230 ------*/

/* ------ GOTO 4580 ------*/

/* ------ GOTO 4670 ------*/

/* ------ GOTO 5430 ------*/

/* ------ GOTO 5690 ------*/

/* ------ GOTO 6220 ------*/

/* ------ GOTO 6270 ------*/

/* ------ GOTO 6290 ------*/

/* ------ GOTO 6650 ------*/

/* ------ GOTO 6720 ------*/

/* ------ GOTO 7260 ------*/

/* ------ GOTO 7320 ------*/

/* ------ GOTO 7550 ------*/

/* ------ GOTO 7720 ------*/

/* ------ GOTO 7850 ------*/

/* ------ GOTO 8120 ------*/

/* ------ GOTO 8220 ------*/

/* ------ GOTO 8290 ------*/

/* ------ GOTO 8420 ------*/

/* ------ GOTO 8460 ------*/

/* ------ GOTO 9120 ------*/

/* ------ GOTO 9210 ------*/



//GOSUB is considered as calling a function with a
//chance to return to the function it was called from
/* ------ GOSUB 3910 ------*/
void maneuverEnergy(){
    currentEnergy = currentEnergy - energyToWarp - 10;
    if (currentEnergy >= 0){
        return;
    }
}

/* ------ GOSUB 6000 ------*/
void shootKlingons(){
    if (localKlingons <= 0){
        return;
    }
     if (starBaseShieldTf != 0)
    {
        printf("STARBASE SHEILDS PROTECT THE ENTERPRISE \n");
        return;
    }

    for (i = 1; i <= 3; i++)
    {
        if (klingonData[i][3] <= 0)
        {
            //6200
        }
        enemyHit = (int) ((klingonData[i][3]/FND(1))*(2+rand(1)));
        currentShield = currentShield - enemyHit;
        klingonData[i][3] = klingonData[i][3]/(3*rand(0));

        printf("%d UNIT HIT ON ENTERPRISE FROM SECTOR %d, %d \n", klingonData[i][1], klingonData[i][2]);
        if (currentShield <= 0)
        {
            //6240
        }
        printf("   <SHIELDS DOWN TO %d UNITS \n", currentShield);
        if (enemyHit < 20)
        {
            //6200
        }
        if ((rand(1)>0.6) || (enemyHit/currentShield <= 0.02))
        {
            //6200
        }
        int rComponent = FNR(1);
        shipDamageArray[rComponent] =  shipDamageArray[rComponent]-enemyHit/currentShield-0.5*rand(1);
        //GOSUB 8790
        printDeviceName(rComponent);
        printf("DAMAGE CONTROL REPORTS %c DAMAGED BY THE HIT \n", shipPartName);
    }
    return;

}

/* ------ GOSUB 6430 ------*/
void shipDocking(){
    int i, j;
    for (i = sector1 - 1; i <= sector1 + 1; i++){
        for (j = sector2 - 1; j <= sector2 + 1; j++){
            if (((int)(i + 0.5) < 1) || ((int)(i + 0.5) > 8) || ((int) (j + 0.5) < 1) || ((int) (j + 0.5) > 8)){
                //6540
            }
            tempObject = ">B<";
            tempObjectPos1 = i;
            tempObjectPos2 = j;
            goSub8830(tempObjectPos1, tempObjectPos2); //GOSUB 8830
            if (mapComparisonTf = 1){
                //6580
            }
        }
    }
    starBaseShieldTf = 0;
    //GOTO 6650

    starBaseShieldTf = 1;
    shipCondition = 'DOCKED';
    currentEnergy = maxEnergy;
    currentTorpedos = maxTorpedos;
    printf("SHIELDS DROPPED FOR DOCKING PURPOSES \n");

    currentShield = 0;
    //GOTO 6720

    if (localKlingons > 0){
        shipCondition = '*RED*';
        //GOTO 6720
    }

    shipCondition  = 'GREEN';
    if (currentEnergy < maxEnergy*0.1){
        shipCondition = 'YELLOW';
    }

    if (shipDamageArray[2]){
        //6770
    }

    printf("\n");
    printf("*** SHORT RANGE SENSORS ARE OUT ***\n");
    printf("\n");
    return;
}

/* ------ GOSUB 8590 ------*/
void emptyPlaceQuad(){
    int R1 = FNR(1);
    int R2 = FNR(1);
    tempObject = '   ';
    tempObjectPos1 = R1;
    tempObjectPos2 = R2;
    compareStringInArray(tempObjectPos1, tempObjectPos2); //GOSUB 8830
     if (mapComparisonTf = 0){
            //8590
    }

    return;

}

/* ------ GOSUB 8670 ------*/
void enterStringQuad(){
     objectLocation = (int) (tempObjectPos2-0.5)*3 + (int) (tempObjectPos1-0.5)*24+1;

    if(strlen(tempObject) != 3){
        printf("ERROR\n");
        //STOP
    }

    if (objectLocation = 1){
        shipCondition = tempObject+ parseRIGHT(quadrantMap, 189);//RIGHT$(quadrantMap, 189);
        return;
    }

    if (objectLocation = 190){
        shipCondition = parseLEFT(shipCondition, 189)+ tempObject;
        return;
    }

    shipCondition = parseLEFT(shipCondition, objectLocation-1);
    return;
}

/* ------ GOSUB 8790 ------*/
void printDeviceName(int input){
    //ON R1 GOTO 8792,8794,8796,8798,8800,8802,8804,8806
    switch (input){
    case 1: //8792
        shipPartName = 'WARP ENGINES';
        return;
    case 2: //8794
        shipPartName = 'SHORT RANGE SENSORS';
        return;
    case 3: //8796
        shipPartName = 'LONG RANGE SENSORS';
        return;
    case 4: //9798
        shipPartName = 'PHASER CONTROL';
        return;
    case 5: //8800
        shipPartName = 'PHOTON TUBES';
        return;
    case 6: //8802
        shipPartName = 'DAMAGE CONTROL';
        return;
    case 7: //8804
        shipPartName = 'SHIELD CONTROL';
        return;
    case 8: //8806
        shipPartName = 'LIBRARY-COMPUTER';
        return;
    }

    return;
}

/* ------ GOSUB 8830 ------*/
void compareStringInArray(){
    //BLOCK 30
    tempObjectPos1 = (int) tempObjectPos1 + 0.5;
    tempObjectPos2 = (int) tempObjectPos2 + 0.5;
    objectLocation = (tempObjectPos2 - 1)*3+(tempObjectPos1 - 1)*24+1;
    mapComparisonTf = 0;

    if (parseMID(quadrantMap, objectLocation, 3) != tempObject){ /*MID$(quadrantMap, objectLocation,3)*/
        return; //RETURN
    }

}

/* ------ GOSUB 9030 ------*/
void quadrantNameInArray(int input){
    //ON Z4 GOTO 9040,9050,9060,9070,9080,9090,9100,9110
    if (quadrantName2 <= 4){
            switch (quadrantName1){
                case 1:
                    shipPartName = 'ANTARES';
                    //GOTO 9210
                case 2:
                    shipPartName = 'RIGEL';
                    //GOTO 9210
                case 3:
                    shipPartName = 'PROCYON';
                    //GOTO 9210
                case 4:
                    shipPartName = 'VEGA';
                    //GOTO 9210
                case 5:
                    shipPartName = 'CANOPUS';
                    //GOTO 9210
                case 6:
                    shipPartName = 'ALTAIR';
                    //GOTO 9210
                case 7:
                    shipPartName = 'SAGITTARIUS';
                    //GOTO 9210
                case 8:
                    shipPartName = 'POLLUX';
                    //GOTO 9210
            }
    }

    //GOTO 9120: ON Z4 GOTO 9130,9140,9150,9160,9170,9180,9190,9200
    switch(quadrantName1){
        case 1:
            shipPartName = 'SIRIUS';
            //GOTO 9210
        case 2:
            shipPartName = 'DENEB';
            //GOTO 9210
        case 3:
            shipPartName = 'CAPELLA';
            //GOTO 9210
        case 4:
            shipPartName = 'BETELGEUSE';
            //GOTO 9210
        case 5:
            shipPartName = 'ALDEBARAN';
            //GOTO 9210
        case 6:
            shipPartName = 'REGULUS';
            //GOTO 9210
        case 7:
            shipPartName = 'ARCTURUS';
            //GOTO 9210
        case 8:
            shipPartName = 'SPICA';
            break;
    }

    if (noNumberNamesTf != 1){
            //ON Z5 GOTO 9230,9240,9250,9260,9230,9240,9250,9260
              switch (quadrantName2){
                case 1:
                    shipPartName = shipPartName + ' I';
                    return;
                case 2:
                    shipPartName = shipPartName + ' II';
                    return;
                case 3:
                    shipPartName = shipPartName + ' III';
                    return;
                case 4:
                     shipPartName = shipPartName + ' IV';
                    return;
                case 5:
                     shipPartName = shipPartName + ' I';
                    return;
                case 6:
                    shipPartName = shipPartName + ' II';
                    return;
                case 7:
                    sshipPartName = shipPartName + ' III';
                    return;
                case 8:
                    shipPartName = shipPartName + ' IV';
                    return;
            }
        return;
    }
}


