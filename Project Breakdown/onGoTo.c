//2140 		ON I GOTO 2300,1980,4000,4260,4700,5530,5690,7290,6270
//(inside for loop in line 2080
   int i;
   for (i = 1; i <= 9; i++){
        if parseLEFT(tempObject, 3) != parseMID(tempObject, 3*i-2, 3){
            //2160
        }
        switch (i){
        case 1:
            printf("COURSE (0-9)");
            scanf("%d", &courseDirectionInput);
            if (courseDirectionInput = 9){
                courseDirectionInput = 1;
            }
        case 2:
            // line 1980
            goSub6430();
        case 3:
            // line 4000
            if (shipDamageArray[3] < 0){
                printf("LONG RANGE SENSORS ARE INOPERABLE");
                //GOTO 1990
                if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] = 0)){
                        //2060
                        printf("COMMAND: ")
                        scanf("%c", tempObject);
                    }
                }
            }
        case 4:
            // line 4260
            if (shipDamageArray[4] < 0){
                printf("PHASERS INORPERATIVE\n");
                //GOTO 1990
                  if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] = 0)){
                        //2060
                        printf("COMMAND: ")
                        scanf("%c", tempObject);
                    }
                }
            }
        case 5:
            // line 4700
            if (currentTorpedos <= 0){
                printf("ALL PHOTON TORPEDOES EXPANDED");
                //GOTO 1990
                if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] = 0)){
                        //2060
                        printf("COMMAND: ")
                        scanf("%c", tempObject);
                    }
                }
            }
        case 6:
            // line 5530
            if (shipDamageArray < 0){
                printf("SHIP CONTROL INOPERABLE\n");
                 //GOTO 1990
                if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] = 0)){
                        //2060
                        printf("COMMAND: ")
                        scanf("%c", tempObject);
                    }
                }
            }
        case 7
            // line 5690
            if (shipDamageArray[6] >= 0){
                //5910
                printf("\nDEVICE            STATE OF REPAIR\n");
                int repairState;
                for(repairState = 1; repairState <= 8; repairState++){
                    goSub8790();
                    printf("%s", shipPartName);
                    printf("   %s", parseLEFT(spacingSpace, 25-strlen(shipPartName));
                    printf("   %d", (int)(shipDamageArray(repairState)*100)*0.01);
                }
            }
        case 8:
            // line 7290
            if (shipDamageArray < 0){
                //GOTO 1990
                 if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] = 0)){
                        //2060
                        printf("COMMAND: ")
                        scanf("%c", tempObject);
                    }
                }
            }
        case 9:
            // line 6270
            printf("THERE WERE %d KLINGON BATTLE CRUISERS LEFT AT THE",  totalKlingon);
            printf("\nEND OF YOUR MISSION");
        }
   }


//6830 		ON I GOTO 6850,6900,6960,7020,7070,7120,7180,7240
int i, j;
for (i = 1, i <= 8; i++){
    for (j = (i -1)*24+1; j <= (i-1)*24+22, i+=3){
        printf(" ", parseMID(quadrantMap, j, 3));
    }
    switch (i){
        case 1:
            //6850
            printf("        STARDATE           %d", (int) (startStarDate*10)*0.01);
            //GOTO 7260
            printf("%c", spacingText);
            return;
        case 2:
            //6900
            printf("        CONDITION          %s", shipCondition )
            //GOTO 7260
            printf("%c", spacingText);
            return;
        case 3:
            //6960
            printf("        QUADRANT           %d, %d", quadrant1, quadrant2);
             //GOTO 7260
            printf("%c", spacingText);
            return;
        case 4:
            //7020
            printf("        SECTOR             %d, %d", sector1, sector2);
            //GOTO 7260
            printf("%c", spacingText);
            return;
        case 5:
            //7070
            printf("        PHOTON TORPEDOES   %d", (int) currentTorpedos);
            //GOTO 7260
            printf("%c", spacingText);
            return;
        case 6:
            //7120
            printf("        TOTAL ENERGY   %d", (int) currenEnergy+currentShield);
            //GOTO 7260
            printf("%c", spacingText);
            return;
        case 7:
            //7180
            printf("        SHIELDS            %d", (int) currentShield);
            //GOTO 7260
            printf("%c", spacingText);
            return;
        case 8:
            //7240
            printf("        KLINGONS REMAINING            %d", (int) totalKlingon);
    }
}

//7350		ON A+1 GOTO 7540,7900,8070,8500,8150,7400
if (libInput + 1 = 1){
   //7540
   // INPUT "DO YOU WANT A HARDCOPY? IS THE TTY ON (Y/N) ";A$
   break;
}
else if (libInput + 1 = 2){
    //7900
    printf("   STATUS REPORT : " );
    sPluralize = '';
    if (totalKlingons > 1){
        sPluralize = 'S';
    }
}
else if (libInput + 1 = 3){
    //8070
    if (localKlingons <= 0){
        //4270
        printf("SCIENCE OFFICER SPOCK REPORTS  'SENSORS SHOW NO ENEMY SHIPS\n");
        printf("                                IN THIS QUADRANT'");
         //GOTO 1990
                 if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] = 0)){
                        //2060
                        printf("COMMAND: ")
                        scanf("%c", tempObject);
                    }
                }
    }
}
else if (libInput + 1 = 4){
    //8500
    if (localStarBases != 0){
        printf("FROM ENTERPRISE TO STARBASE : \n" )
        warpInput = starBaseSector1;
        //X = starBaseSector2; block 26
        // GOTO 8120
        tempTorpedoInitialCoord1 = sector1;
        tempTorepdoInitialCoord2 = sector2;
        //GOTO 8220
        tempTorpedoFinalCoord2 = tempTorpedoFinalCoord2 - tempTorpedoInitialCoord2;
        tempTorpedoInitialCoord2 = tempTorpedoInitialCoord1 - tempTorpedoFinalCoord1;
        if (tempTorpedoFinalCoord2 < 0){
            //8350
            if (tempTorpedoInitialCoord2 > 0){
                tempTorpedoInitialCoord1 = 3
                //GOTO 8420
                if (abs(tempTorpedoInitialCoord2) >= abs(tempTorpedoFinalCoord2)){
                    //8450
                    printf("DIRECTION =%d\n", tempTorpedoInitialCoord1+(abs(tempTorpedoFinalCoord2)+abs(tempTorpedoInitialCoord2)));

                }
            }
        }
    }
}
else if (libInput + 1 = 5){
    //8150
    printf("DIRECTION/DISTANCE CALCULATOR : ");
    printf("YOU ARE AT QUADRANT %d, %d SECTOR %d, %d", quadrant1, quadrant2, sector1, sector2);
    printf("PLEASE ENTER\n");
    printf("INITIAL COODINATES (x,y)");
    scanf("%d %d", &tempTorpedoInitialCoord1, &tempTorpedoInitialCoord2);
    printf("\nFINAL COORDINATES (x,y)");
    scanf("%d %d", &tempTorpedoFinalCoord1, &tempTorpedoFinalCoord2);
}
else if (libInput + 1 = 6){
    //7400
    libMenu = 0;
    noNumberNamesTf = 1;
    printf("                        THE GALAXY\n");
    //GOTO 7550

}
else{
    continue;
}

//8790		ON R1 GOTO 8792,8794,8796,8798,8800,8802,8804,8806
switch (R1) {
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

//9030		IF Z5 <= 4 THEN
//		ON Z4 GOTO 9040,9050,9060,9070,9080,9090,9100,9110
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

//9120 		ON Z4 GOTO 9130,9140,9150,9160,9170,9180,9190,9200
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


//9210 		IF G5<>1 THEN
//		ON Z5 GOTO 9230,9240,9250,9260,9230,9240,9250,9260
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

