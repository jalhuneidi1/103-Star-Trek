#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "StarTrekRndNum.h"
#include "StarTrekSetup.h"
//#include "MidLeftRight.h"
//#include "GOSUB.h"
//#include "GOTO.h"

#define MAX_STRING 50

int main(void) {
//{Variable Declarations                    INCOMPLETE
    //Stardate Variables
    int currentStardate, startStardate, daysRemaining;

    //Ship Resource Variables
    int currentEnergy, maxEnergy;
    int currentTorpedos, maxTorpedos;
    int currentShield, multiTargetMod;
    int shipPartInt; char shipPartName;
    double repairTime;


    //Starbase Variables
    int localStarBases, starBaseTotal;
    int starBaseSector1, starBaseSector2;
    int localStars;

    //Klingon Variables
    int localKlingons, startKlingons, totalKlingons;
    int klingonShieldMod, quadrantDamageMod;

    //Navigation Variables
    int quadrant1, quadrant2, quadrantName1, quadrantName2;
    char quadrantNameString[MAX_STRING];
    int sector1,sector2,tempQuad1, tempQuad2;
    int tempTorpedoInitialCoord1, tempTorpedoInitialCoord2;
    int tempTorpedoFinalCoord1, tempTorpedoFinalCoord2;
    bool outOfBoundsTf;

    //Object Position Variables
    int positionMod1, positionMod2;
    int tempObjectPos1,tempObjectPos2;
    int torpedoTracker1, torpedoTracker2;
    bool mapComparisonTf;

    //Warp Variables
    int courseDirectionInput, warpInput, energyToWarp;
    int travelTime, warpSpeedDamageMod;
    char warpMessage[MAX_STRING];

    //Display Variables
    char commandDisplay[MAX_STRING],shipCondition[MAX_STRING];
    int objectLocation;
    char quadrantMap[MAX_STRING],tempObject[MAX_STRING];
    char spacingText[MAX_STRING], spacingSpace[MAX_STRING];
    char sPluralize[MAX_STRING],verbPluralize[MAX_STRING];

    //Functional Variables
    double random1, random2;
    double inputX, libInput;
    bool noNumberNamesTf, starBaseShieldTf, queueDamageReportTf;
    int enemyHit, printAdvance, libMenu;
    int i, j;

    //Array initialization
    int galaxyInfo[9][9];
    int klingonData[3][3];
    int navArray[10][3];
    int scannerArray[3];
    int shipDamageArray[9];
    int tempInfo[9][9];


//{ Alt Declarations w/BASIC Equivalents
/* ------ Variable Declaration ------*/
/*
int libInput, tempTorpedoInitialCoord2;     // A
int localStarBases, starBaseSector1, starBaseSector2, starBaseTotal;    // B3, B4, B5, B9
int courseDirectionInput, tempTorpedoInitialCoord1;     // C1
int starBaseShieldTf, queueDamageReportTf, repairTime, quadrantDamageMod, warpSpeedDamageMod; //D0, D1, D3, D4, D6
int currentEnergy, maxEnergy;       // E, E0
int noNumberNamesTf;       // G5
int enemyHit, multiTargetMod, libMenu;      // H, H1, H8
int i, j, l;         // index
int printAdvance;       // J0
int localKlingons, startKlingons, totalKlingons;        //K3, K7, K9
int energyToWarp;       // N
int currentTorpedos, maxTorpedos;       // P, P0
int quadrant1, quadrant2, tempQuad1, tempQuad2;        // Q1, Q2, Q4, Q5
//random variables R1 R2 defined within main when instance is mentioned in BASIC Code
int currentShield, sector1, sector2, localStars, objectLocation, klingonShieldMod;      // S, S1, S2, S3, S8, S9
int startStardate, currentStardate, travelTime, daysRemaining;      // T, T0, T8, T9
int warpInput, tempTorpedoFinalCoord1;       // W1
int tempTorpedoFinalCoord2, positionMod1, positionMod2, torpedoTracker1, outOfBoundsTf;     // X X1, X2, X3, X5
int torpedoTracker2;    // Y3
// x and y variables will be mentioned in line depending on BASIC Code
int tempObjectPos1, tempObjectPos2, mapComparisonTf, quadrantName1, quadrantName2;      // Z1, Z2, Z3, Z4, Z5
/**/

/* ------ Array Declaration ------*/
/*
int navArray[9][9];       // C( i, j ) array to make the rotary navigation work correctly
int shipDamageArray[9];      // D( i ) array stores whether sections of ship are damaged or not
int galaxyInfo[9][9];     // G( i, j ) array stores number of klingon, bases and stars in given quadrant
int klingonData[3][3];    // K( i, j ) array stores klingon ship data
int scannerArray[3];    // N( i ) array to do with long range scanner code
int tempInfo[9][9];        // Z( i, j) array secondary quadrant information
/**/

/* ------ Character Declaration ------*/
/*
char tempObject, commandDisplay;          // A$, A1$
char shipCondition;           // C$
char shipPartName;           // G2$
char spacingText;          // O1$
char quadrantMap;          // Q$
char sPluralize, verbPluralize;           // X$, X0$
char spacingSpace;          // Z$
/**/
    //}
//}
//{Block  1: Enterprise Drawing             -COMPLETE, COMPILED, TESTED
                //BASIC lines 220-250

    //START
    //Draw opening image of the Enterprise.
    DrawEnterprise();

//********End of Block 1********
//}
//{Block  2: Stardate and Base Value Setup  -COMPLETE, COMPILED, TESTED

                //BASIC lines 260-475
    strcpy(spacingSpace,"                         ");//Create 25 space characters in spacingSpace

    //Initialize Stardate
    startStardate=(rand()%2000) + 2000;
    currentStardate= startStardate;

    //Provide starting ship resource values
    WeaponsStartingValues(&currentEnergy, &maxEnergy, &currentTorpedos, &maxTorpedos, &currentShield, &starBaseShieldTf, &klingonShieldMod);

    starBaseTotal=2;
    totalKlingons=0;
    strcpy(sPluralize, "");
    strcpy(verbPluralize," IS ");

//********End of Block 2********
//}*
//{Block  3: Initialize Enterprise Position -COMPLETE, COMPILED, TESTED
                //BASIC lines 480-710
    quadrant1=RndIntOneToEight();
    quadrant2=RndIntOneToEight();
    sector1=RndIntOneToEight();
    sector2=RndIntOneToEight();

    NavArraySetup(navArray); //set up array to control rotary directional entry
    DamageArraySetup(shipDamageArray); //set initial ship damage to 0's

    strcpy(commandDisplay, "NAVSRSLRSPHATORSHEDAMCOMXXX");

//********End of Block 3********
//}
//{Block  4: Galaxy Setup                   -COMPLETE, UNCOMPILED
                //BASIC lines 810-1300
    for (i=1; i==8; ++i) {
            for (j=1; i==8; ++i) {
                    localKlingons=0;
                    tempInfo[i][j]=0;
                    random1=RndZeroToOne();

                    bool gotoSwitch980 = 0; //when gotoSwitch is on, skip the next if statements until BASIC line 980
                    if (random1>.98) {
                        localKlingons=3;
                        totalKlingons=totalKlingons+3;

                        gotoSwitch980 = 1; //GOTO 980
                    }
                    if ((random1>.95 && random1<.98) && (gotoSwitch980==0)) {
                        localKlingons=2;
                        totalKlingons=totalKlingons+2;

                        gotoSwitch980 = 1; //GOTO 980
                    }

                    if ((random1>.80 && random1<.95) && (gotoSwitch980==0)) {
                        localKlingons=1;
                        totalKlingons=totalKlingons+1;
                    }
//980
                    localStarBases=0; gotoSwitch980 = 0;

                    if (RndZeroToOne()>.96) {
                        localStarBases=1;
                        starBaseTotal=starBaseTotal+1;
                    }
                    galaxyInfo[i][j]=localKlingons*100+localStarBases*10+RndIntOneToEight();
                    //Value of info array at current coordinates is equal to number
                    //of Klingons times 100, plus either a 1 or a 0 in the tens
                    //place if a base is there or not, plus a random integer
                    //between 1 and 8 in the ones place(# of stars).

                    if (totalKlingons>daysRemaining) {
                    //If the total number of Klingons, totalKlingons, is greater than the randomly assigned integer between
                    //25 and 34, T9 (number of days to complete mission)
                    //then the number of days you have to complete the mission instead equals the total number of klingons plus 1
                        daysRemaining=totalKlingons+1;
                    }

                    if (starBaseTotal==0) { //if (starBaseTotal != 0) GOTO 1200
                        if (galaxyInfo[quadrant1][quadrant2]<200) {
                            galaxyInfo[quadrant1][quadrant2]= galaxyInfo[quadrant1][quadrant2] +120;
                            totalKlingons=totalKlingons+1;
                        }
                        starBaseTotal=1;
                    }

                galaxyInfo[quadrant1][quadrant2]=galaxyInfo[quadrant1][quadrant2] +10; // this section is increasing the amount of bases
                quadrant1=RndIntOneToEight();
                quadrant2=RndIntOneToEight();
//1200
                startKlingons=totalKlingons;

                if (starBaseTotal!=1) {
                        strcpy(sPluralize,"S");
                        strcpy(verbPluralize," ARE ");
                }

                printf("YOUR ORDERS ARE AS FOLLOWS : \n");
                printf("DESTROY THE %d KLINGON WARSHIPS WHICH HAVE INVADED\n", totalKlingons);
                printf(" THE GALAXY BEFORE THEY CAN ATTACK FEDERATION HEADQUARTERS\n");
                printf(" ON STARDATE %d THIS GIVES YOU %d DAYS. THERE %s \n",(currentStardate+daysRemaining), daysRemaining,verbPluralize);
                printf("%d STARBASE %s IN THE GALAXY FOR RESUPPLYING YOUR SHIP.\n", starBaseTotal, sPluralize);

            }
    }
    printf("\n");
 	i=RndIntOneToEight();
//********End of Block 4********
//}
//{Block  5: Entering New Quadrant          -NEEDS quadrantMap COMPLETION
                //BASIC lines 1310-1650
 	quadrantName1=quadrant1;
	quadrantName2=quadrant2;
	localKlingons=0;
	localStarBases=0;
	localStars=0;
	noNumberNamesTf=0;
	quadrantDamageMod=.5*RndIntOneToEight();
	tempInfo[quadrant1][quadrant2]= galaxyInfo[quadrant1][quadrant2];


    if ( !((quadrant1 <1)||(quadrant1 >8)||(quadrant2 <1)||(quadrant2 >8))){ //IF quadrant1<1 OR quadrant1>8 OR quadrant2<1 OR quadrant2>8 THEN 1600
        quadrantNameInArray(quadrantName1,quadrantName2,quadrantNameString,noNumberNamesTf); //GOSUB 9030
        printf("\n");
        bool gotoSwitch1500 = 0;
        if (currentStardate == startStardate){ //IF T0<>T THEN 1490
            printf("YOUR MISSION BEGINS WITH YOUR STARSHIP LOCATED\n");
            printf("IN THE GALACTIC QUADRANT, '%s'.\n", quadrantNameString);
            gotoSwitch1500 = 1; //GOTO 1500
        }
//1490
        if (gotoSwitch1500 != 1){
            printf("NOW ENTERING %s QUADRANT . . .\n", quadrantNameString);
        }
//1500
        printf("\n");
        localKlingons=floor(galaxyInfo[quadrant1][quadrant2]*.01);
        localStarBases=floor(galaxyInfo[quadrant1][quadrant2]*.1)-10*localKlingons;

        localStars=galaxyInfo[quadrant1][quadrant2]-100*localKlingons-10*localStarBases;
        if (localKlingons > 0){ //IF localKlingons=0 THEN 1590
            printf("COMBAT AREA      CONDITION RED\n");;
            if (currentShield <= 200){
                printf("   SHIELDS DANGEROUSLY LOW\n");
            }
        }
//1590
        for (i=1; i <= 3; ++i){
            klingonData[i][1]=0;
            klingonData[i][2]=0;
        }
    }
//1600
 	for (i=1; i <= 3; ++i){
		klingonData[i][3]=0;
 	}

	//quadrantMap=spacingSpace+spacingSpace+spacingSpace+spacingSpace+spacingSpace+spacingSpace+spacingSpace+LEFT$(spacingSpace,17)


//********End of Block 5********
//}
//{Block  6: Position Objects in Quadrant   -NEEDS shipDocking, enterStringQuad, LEFTMIDRIGHT
                //BASIC lines 1660-1980
    //Position Enterprise
 	strcpy(tempObject,"<E>");
	tempObjectPos1=sector1;
	tempObjectPos2=sector2;
	enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);//GOSUB 8670

	//Position Klingons
	if (localKlingons >= 1){ //IF localKlingons<1 THEN 1820
        for(i=1; i <=localKlingons; ++i){
            emptyPlaceQuad(tempObject,tempObjectPos1,tempObjectPos2);//GOSUB 8590;
            strcpy(tempObject,"+K+");
            tempObjectPos1=random1;
            tempObjectPos2=random2;

            enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);//GOSUB 8670;
            klingonData[i][1]=random1;
            klingonData[i][2]=random2;
            klingonData[i][3]=klingonShieldMod*(0.5+RndIntOneToEight());
        }
	}
//1820
 	//Position StarBase
 	if (localStarBases>=1){ //IF localStarBases<1 THEN 1910
        emptyPlaceQuad(tempObject,tempObjectPos1,tempObjectPos2);//GOSUB 8590
        strcpy(tempObject,">B<");
        tempObjectPos1=random1;
        starBaseSector1=random1;
        tempObjectPos2=random2;
        starBaseSector2=random2;
        enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);//GOSUB 8670
 	}
//1910
	//Position Stars
	for (i=1; i <=localStars; ++i){
		emptyPlaceQuad(tempObject,tempObjectPos1,tempObjectPos2);//GOSUB 8590
		strcpy(tempObject," * ");
		tempObjectPos2=random2;
		tempObjectPos1=random1;
		enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);//GOSUB 8670;
	}
//1980
	shipPreDocking();//GOSUB 6430
	shipDocking();

//********End of Block 6********
//}
//{Block  7: Enter Command                  MISSING GOTO'S, LEFTMIDRIGHT
                //BASIC lines 1990-2280
//1990
 	if (((currentShield+currentEnergy)<=10) || ((currentEnergy<=10)&&(!(shipDamageArray[7]==0)))){
        printf("\n");
        printf("** FATAL ERROR **   YOU'VE JUST STRANDED YOUR SHIP IN \n");

        printf("SPACE\n");;
        printf("YOU HAVE INSUFFICIENT MANEUVERING ENERGY,\n");;

        printf(" AND SHIELD CONTROL\n");;
        printf("IS PRESENTLY INCAPABLE OF CROSS\n");;
        printf("-CIRCUITING TO ENGINE ROOM!!\n");;
        //GameOver();//GOTO 6220
 	}

//2060
 	printf("COMMAND: ");
 	scanf("%s", &tempObject);

 	for (i=1; i <=9; ++i){
           //IF LEFT$(tempObject,3)<>MID$(commandDisplay,3*i-2,3) THEN 2160
		if (parseLEFT(tempObject, 3) != parseMid(commandDisplay, 3*i-2, 3)){
      //2160
      }
      //ON i GOTO 2300,1980,4000,4260,4700,5530,5690,7290,6270
 		switch (i){
        case 1:
            printf("COURSE (0-9)");
            scanf("%d", &courseDirectionInput);
            if (courseDirectionInput == 9){
                courseDirectionInput = 1;
            }
            if (!((courseDirectionInput>=1)&&(courseDirectionInput<9))){ //IF courseDirectionInput>=1 AND courseDirectionInput<9 THEN 2350
                printf("   LT. SULU REPORTS, 'INCORRECT COURSE DATA, SIR!'");
                //GOTO 1990
            }
        case 2:
            shipPreDocking();//GOTO 1980
            shipDocking();
            //GOTO 1990

        case 3:
            // line 4000
            if (shipDamageArray[3] < 0){
                printf("LONG RANGE SENSORS ARE INOPERABLE");
                //GOTO 1990
                if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] == 0)){
                        //2060
                        printf("COMMAND: ");
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
                    if ((currentEnergy > 10) || (shipDamageArray[7] == 0)){
                        //2060
                        printf("COMMAND: ");
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
                    if ((currentEnergy > 10) || (shipDamageArray[7] == 0)){
                        //2060
                        printf("COMMAND: ");
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
                    if ((currentEnergy > 10) || (shipDamageArray[7] == 0)){
                        //2060
                        printf("COMMAND: ");
                        scanf("%c", tempObject);
                    }
                }
            }
        case 7:
            // line 5690
            if (shipDamageArray[6] >= 0){
                //5910
                printf("\nDEVICE            STATE OF REPAIR\n");
                for(shipPartInt = 1; shipPartInt <= 8; shipPartInt++){
                    goSub8790();
                    printf("%s", shipPartName);
                    printf("   %s", parseLEFT(spacingSpace, 25-strlen(shipPartName)));
                    printf("   %d", (int)(shipDamageArray[shipPartInt]*100)*0.01);
                }
            }
        case 8:
            // line 7290
            if (shipDamageArray < 0){
                //GOTO 1990
                 if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] == 0)){
                        //2060
                        printf("COMMAND: ");
                        scanf("%c", tempObject);
                    }
                }
            }
        case 9:
            //gotoSwitch6270 = 1;
            GameOver();// line 6270
        }
 	}

//2160
	printf("ENTER ONE OF THE FOLLOWING; \n");

 	printf("  NAV  (TO SET COURSE)\n");
	printf("  SRS  (FOR SHORT RANGE SENSOR SCAN)\n");
 	printf("  LRS  (FOR LONG RANGE SENSOR SCAN)\n");
 	printf("  PHA  (TO FIRE PHASERS)\n");
 	printf("  TOR  (TO FIRE PHOTON TORPEDOES)\n");
 	printf("  SHE  (TO RAISE OR LOWER SHIELDS)\n");
 	printf("  DAM  (FOR DAMAGE CONTROL REPORTS)\n");
 	printf("  COM  (TO CALL ON LIBRARY-COMPUTER)\n");
 	printf("  XXX  (TO RESIGN YOUR COMMAND)\n");;
	printf("\n");
	//GOTO  1990

//********End of Block 7********
//}
//{Block  8: Course Control                 MISSING GOTO'S
                //BASIC lines 2290-2570
//2300
 	printf("COURSE (0-9) ");
 	scanf("%d", &courseDirectionInput);
	if (courseDirectionInput==9){
		courseDirectionInput=1;
	}

 	if (!((courseDirectionInput>=1) && (courseDirectionInput<9))){
     	printf("   LT. SULU REPORTS, 'INCORRECT COURSE DATA, SIR!'\n");;
        //GOTO 1990
 	}

//2350
 	strcpy(warpMessage,"8");
	if (shipDamageArray[1]<0){
        strcpy(warpMessage,"0.2");
	}

 	printf("WARP FACTOR (0-%s\n", warpMessage);
	scanf("%d", &warpInput);

	if ((shipDamageArray[1]<0) && (warpInput>.2)){
            //THEN 2470
	}

 	if ((warpInput>0) && (warpInput<=8)){
            //THEN 2490
            }

 	if (warpInput == 0){
            //THEN 1990
 	}


 	printf("   CHIEF ENGINEER SCOTT REPORTS 'THE ENGINES WON'T TAKE\n");;
 	printf(" WARP %d!'\n", warpInput);;
	//GOTO 1990

 	printf("WARP ENGINES ARE DAMAGED.  MAXIUM SPEED = WARP 0.2\n");;
	//GOTO 1990

//2490
 	energyToWarp=floor(warpInput*8+.5);
	if (currentEnergy-energyToWarp>=0){
        //GOTO 2590
	}

 	printf("ENGINEERING REPORTS   'INSUFFICIENT ENERGY AVAILABLE\n");
 	printf("                       FOR MANEUVERING AT WARP %s!'\n", warpInput);
 	if ((currentShield<energyToWarp-currentEnergy) || (shipDamageArray[7]<0)){
            //THEN 1990
 	}

 	printf("DEFLECTOR CONTROL ROOM ACKNOWLEDGES %d UNITS OF ENERGY\n", currentShield);
 	//GOTO 1990
 	printf("                         PRESENTLY DEPLOYED TO SHIELDS.\n");


//********End of Block 8********
//}
//{Block  9: Klingon's Move/Fire            MISSING GOSUB'S, GOTO'S
                //BASIC lines 2580-3050
    for (i = 1; i >= localKlingons; i++)
    {
        if (klingonData[i][3] == 0)
        {
            break;
        }
        strcpy(tempObject, " ");
        tempObjectPos1 = klingonData[i][1];
        tempObjectPos2 = klingonData[i][2];
        //GOSUB 8670
        enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);
        //GOSUB 8590
        emptyPlaceQuad(tempObject,tempObjectPos1,tempObjectPos2);

        klingonData[i][1]= tempObjectPos1;
        klingonData[i][2] = tempObjectPos2;
        strcpy(tempObject,"+K+");
        //GOSUB 8670
        enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);
    }
    // line2700();

    for (i = 1; i <= 8; i++)
    {
        if (shipDamageArray[i]>=0)
        {
            //line 2880
        }
        shipDamageArray[i] = shipDamageArray[i]+warpSpeedDamageMod;
        if ((shipDamageArray[i] > - 0.1) && (shipDamageArray[i] < 0))
        {
            shipDamageArray[i] = -0.1;
            //GOTO 2880
        }
        if (shipDamageArray[i] < 0)
        {
            //line 2880
        }
        if (queueDamageReportTf != 1)
        {
            queueDamageReportTf = 1;
            printf("DAMAGE CONTROL REPORT: \n");
        }
        printf("        "); //TAB
        int R1 = i;
        //GOSUB 8790
        printDeviceName(shipPartInt,shipPartName);
        printf("%s: REPAIR COMPLETED\n", shipPartName);
    }

    shipPartInt = RndIntOneToEight();

    if (shipPartInt > 0.2){
        //line 3070
    }
    if (shipPartInt >= 0.6){
        //line 3000
    }

    shipDamageArray[shipPartInt] = shipDamageArray[shipPartInt] - (RndZeroToOne()*5)+1;
    printf("DAMAGE CONTROL REPORT: \n");
    //GOSUB 8790
    printDeviceName(shipPartInt,shipPartName);
    printf(" %s: DAMAGED\n", shipPartName);

    shipDamageArray[shipPartInt] = shipDamageArray[shipPartInt] - (RndZeroToOne()*3)+1;
    printf("DAMAGE CONTROL REPORT: \n");
    //GOSUB 8790
    printDeviceName(shipPartInt,shipPartName);
    printf("%s: STATE OF REPAIR IMPROVED\n", shipPartName);
    printf(" \n");

//********End of Block 9********
//}
//{Block 10: Begin Moving Starship          MISSING GOSUB'S, GOTO'S, LEFTMIDRIGHT
                //BASIC lines 3060-3460
    strcpy(tempObject,' ');
    tempObjectPos1 = sector1;
    tempObjectPos2 = sector2;
    //GOSUB 8670
    printDeviceName(shipPartInt,shipPartName);
    positionMod1 = navArray[courseDirectionInput][1] +((navArray[courseDirectionInput+1][1] -navArray[courseDirectionInput][1])*(courseDirectionInput-(int)courseDirectionInput));
    double tempX = sector1;
    double tempY = sector2;
    positionMod2 = navArray[courseDirectionInput][2]+((navArray[courseDirectionInput+1][2] - navArray[courseDirectionInput][2])*(courseDirectionInput-(int)courseDirectionInput));
    tempQuad1 = quadrant1;
    tempQuad2 = quadrant2;

    for (int i = 1; i >= energyToWarp; i++)
    {
        sector1 = sector1 + positionMod1;
        sector2 = sector2 + positionMod2;
        if ((sector1 < 1) || (sector1 >= 9 ) || (sector2 < 1) || (sector2 >= 9))
        {
            //line 3500
        }
        objectLocation = floor(sector1*24) + floor(sector2 * 3) - 26;
        //if (parseMID(quadrantMap,objectLocation,2)=' ')
        {
            //line 3360
        }
        sector1 = floor(sector1 - positionMod1);
        sector2 = floor(sector2 - positionMod2);
        printf(" WARP ENGINES SHUT DOWN AT \n");
        printf("SECTOR %d, %d DUE TO BAD NAVIGATION\n", sector1, sector2);
        //line 3370
    }
    sector1 = floor(sector1);
    sector2 = floor(sector2);
    strcpy(tempObject, '<E>');
    tempObjectPos1 = floor(sector1);
    tempObjectPos2 = floor(sector2);
    //GOSUB 8670
    enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);
    //GOSUB 3910
    maneuverEnergy(tempObjectPos1, tempObjectPos2);
    travelTime = 1;

    if (warpInput < 1)
    {
        travelTime = 0.1*((int) 10* warpInput);
    }
    startStardate = startStardate + travelTime;
    double calc = currentStardate + daysRemaining;

    if (startStardate > calc)
    {
        //line 6220
    }
//********End of Block 10********
//}
//{Block 11: See if Docked, then Command    MISSING FINISHED FUNCITONS IN HEADER
                //BASIC lines 3470-3480
//GOSUB 6430 function
bool dangerDockingTf = 0;
shipPreDocking();
shipDocking();
//GOTO 1980

//********End of Block 11********
//}
//{Block 12: Exceeded Quadrant Limits       MISSING GOTO'S, GOSUB'S
                //BASIC lines 3490-3890
    int quadX = 8 * quadrant1 + quadX + energyToWarp * positionMod1;
    int quadY = 8 * quadrant2 + quadX + energyToWarp * positionMod2;
    quadrant1 = floor(quadX/8);
    quadrant2 = floor(quadY/8);
    sector1 = floor(quadX-quadrant1*8);
    sector2 = floor(quadY - quadrant2 *8);

    if (sector1 == 0){
        quadrant1 = quadrant1 - 1;
        sector1 = 8;
    }
    if (sector2 == 0){
        quadrant2 = quadrant2 -1;
        sector2 = 8;
    }
    outOfBoundsTf = 0;
    if (quadrant1 < 1){
        outOfBoundsTf = 1;
        quadrant1 = 1;
        sector1 = 1;
    }
    if (quadrant1 > 8){
        outOfBoundsTf =1;
        quadrant1 = 8;
        sector1 = 8;
    }
    if (quadrant2 < 1){
        outOfBoundsTf = 1;
        quadrant2 = 1;
        sector2 = 1;
    }
    if (quadrant2 > 8){
        outOfBoundsTf = 1;
        quadrant2 = 8;
        sector2 = 8;
    }
    if (outOfBoundsTf == 0){
        //line 3860
    }
    printf("LT. UHURA REPORTS MESSAGE FROM STARFLEET COMMAND : \n");
    printf("  'PERMISSION TO ATTEMPT CROSSING OF GALACTIC PERIMETER\n");
    printf(" IS HEREBY *DENIED*.  SHUT DOWN YOUR ENGINES.' \n");
    printf("CHIEF ENGINEER SCOTT REPORTS  'WARP ENGINES SHUT DOWN\n");
    printf(" AT SECTOR %d , %d OF QUADRANT %d, %d.\n", sector1, sector2, quadrant1, quadrant2);

    if (startStardate > currentStardate+ daysRemaining)
    {
        //line 6220 function
    }

    int calc1 = 8*quadrant1+quadrant2;
    int calc2 = 8*tempQuad1+tempQuad2;
    if (calc1 == calc2)
    {
        //function for line 3370
    }
    startStardate = startStardate +1;
    //GOSUB 3910
    maneuverEnergy();

    //GOTO 1320

//********End of Block 12********
//}
//{Block 13: Maneuvering Energy Transact    MISSING EXISTANCE AS A FUNCTION
                //BASIC lines 3900-3980
    currentEnergy = currentEnergy - energyToWarp;
    if (currentEnergy >= 0)
    {
        return;
    }

    printf("SHIELD CONTROL SUPPLIES ENERGY TO COMPLETE MANEUVER.\n");
    currentShield = currentShield + currentEnergy;
    currentEnergy = 0;
    if (currentShield <= 0)
    {
        currentShield = 0;
    }
    return;

//********End of Block 13********
//}
//{Block 14: Long Range Sensor Scan         MISSING GOTO'S, LEFTMIDRIGHT
                //BASIC lines 3990-4240
    if (shipDamageArray[3] < 0){
        printf("LONG RANSE SENSORS ARE INOPERABLE.\n");
        //GOTO 1990
    }
    printf("LONG RANGE SCAN FOR QUADRANT %d, %d. \n", quadrant1, quadrant2);
    strcpy(spacingText,"     -------------------");
    printf("%c \n", spacingText);
    for (int i = quadrant1-1; i <= quadrant1+1; i++){
        scannerArray[1] = -1;
        scannerArray[2] = -2;
        scannerArray[3] = -3;
        for (int j = quadrant2 - 1; j <= quadrant2+1; j++){
            if ((i > 0) && (i < 9) && (j > 0) && (j<9)){
                scannerArray[j - quadrant2+2] = galaxyInfo[i][j];
                tempInfo[i][j] = galaxyInfo[i][j];
            }
        }
        for (int l = 1; l <= 3; l++){
            printf(": \n");
            if (scannerArray[l] < 0){
                print("*** ");
                //GOTO 4230
            }
            //PRINT RIGHT$(STR$(N(L)+1000),3);"
            printf("%s", parseRIGHT(strcpy((scannerArray[l]+1000),3)));
        }
        printf(" : \n");
        printf("%c \n", spacingText);
    }
    //GOTO 1990

//********End of Block 14********
//}
//{Block 15: Phasor Firing Controls         MISSING GOTO'S, GOSUB'S, SUB FUNCTIONS
                //BASIC lines 4250-4680
    if (shipDamageArray[4] < 0){
        printf("PHASERS  INOPERATIVE.\n");
        //GOTO 1990
    }
    if (localKlingons > 0){
        //4330
    }
    printf("SCIENCE OFFICER SPOCK REPORTS 'SENSORS SHOW NO ENEMY SHIPS \n");
    printf("/t/t/t/t/t/t/t IN THIS QUADRANT'\n");
    //GOTO 1990

    if (shipDamageArray[8] < 0){
        printf("COMPUTER FAILURE HAMEPERS ACCURACY \n");
    }
    printf("PHASERS LOCKED ON TARGET;\n");
    printf("ENERGY AVAILABLE = %d UNITS. \n", currentEnergy);
    printf("NUMBER OF UNITS TO FIRE?");
    scanf("%d", &inputX);
    printf("\n");
    if (inputX <= 0){
        //1990
    }
    if (currentEnergy - inputX < 0){
        printf("ENERGY AVAILABLE = %d UNITS. \n", currentEnergy);
    }
    currentEnergy = currentEnergy - inputX;
    if(shipDamageArray[7] < 0){
        inputX = inputX*RndZeroToOne();
    }
    multiTargetMod = floor(inputX/localKlingons);
    for (i = 1; i <= 3; i++){
        if (klingonData[i][3] <= 0){
            //4670
        }

        multiTargetMod = floor((multiTargetMod/phasorDamageMod(0))*(RndZeroToOne()*2));
        if (multiTargetMod > (0.15*klingonData[i][3])){
            //4530
        }
        printf("SENSORS SHOW NO DAMAGE TO ENEMY AT %d, %d.\n", klingonData[i][3], klingonData[i][2]);
        //GOTO 4670
        klingonData[i][3] = klingonData[i][3] - multiTargetMod;
        printf("%d UNIT HIT ON KLINGON AT SECTOR %d,\n", multiTargetMod, klingonData[i][1]);
        printf("%d\n", klingonData[i][2]);
        if (klingonData[i][3] <= 0){
            printf("*** KLINGON DESTROYED ***\n" );
            //GOTO 4580
        }

        printf("   (SENSORS SHOW %d UNITS REMAINING)\n", klingonData[i][3] );
        //GOTO 4670

        localKlingons = localKlingons - 1;
        totalKlingons = totalKlingons - 1;
        tempObjectPos1 = klingonData[i][3];
        tempObjectPos2 = klingonData[i][2];
        strcpy(tempObject,"   ");
        //GOSUB 8670
        enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);

        klingonData[i][3] = 0;
        galaxyInfo[quadrant1][quadrant2] =  galaxyInfo[quadrant1][quadrant2] - 100;
        tempInfo[quadrant1][quadrant2] =  galaxyInfo[quadrant1][quadrant2];
        if (totalKlingons <= 0){
            //6370
        }
        //GOSUB 6000
        shootKlingons();
        //GOTO 1990
    }
//********End of Block 15********
//}
//{Block 16: Photon Torpedo Controls        MISSING GOTO'S, GOSUB'S
                //BASIC lines 4690-5510
    if (currentTorpedos <= 0){
        printf("ALL PHOTON TORPEDOES EXPENDED \n");
        //GOTO 1990
    }
    if (shipDamageArray[5] < 0){
        printf("ALL PHOTON TUBES ARE NOT OPERATIONAL\n");
        //GOTO 1990
    }

    printf("PHOTON TORPEDO COURSE (1-9): \n");
    scanf("%d", courseDirectionInput);
    if (courseDirectionInput == 9){
        courseDirectionInput =  1;
    }
    if ((courseDirectionInput >=1) && (courseDirectionInput < 9)){
        // GOTO 4850
        positionMod1 = navArray[courseDirectionInput][1]+(navArray[courseDirectionInput+1][1]-navArray[courseDirectionInput][1])*(courseDirectionInput - floor(courseDirectionInput));
        currentEnergy = currentEnergy - 2;
        currentTorpedos = currentTorpedos -1;
    }

    printf("ENSIGN CHEKOV REPORTS, 'INCORRECT COURSE DATA, SIR' \n");
    //GOTO 1990
    positionMod1 = navArray[courseDirectionInput][1]+(navArray[courseDirectionInput+1][1]-navArray[courseDirectionInput][1])*(courseDirectionInput - floor(courseDirectionInput));
    currentEnergy = currentEnergy - 2;
    currentTorpedos = currentTorpedos -1;

    positionMod2 = navArray[courseDirectionInput][2]+(navArray[courseDirectionInput+1][2]-navArray[courseDirectionInput][2])*(courseDirectionInput - floor(courseDirectionInput));
    double xTemp = sector1;
    double yTemp = sector2;

    printf("TORPEDO TRACK: \n");
    xTemp = xTemp + positionMod1;
    yTemp = yTemp + positionMod2;
    torpedoTracker1 = floor(xTemp+ 0.5);
    torpedoTracker2 = floor(yTemp + 0.5);

    if ((torpedoTracker1 < 1) || (torpedoTracker1 > 8) || (torpedoTracker2 < 1) || (torpedoTracker2 > 8)){
        //GOTO 5490
    }

    printf("%d, %d \n", torpedoTracker1, torpedoTracker2);
    strcpy(tempObject," ");
    tempObjectPos1 = xTemp;
    tempObjectPos2 = yTemp;
    //GOSUB 8830
    compareStringInArray(tempObject,tempObjectPos1,tempObjectPos2,objectLocation,mapComparisonTf,quadrantMap,objectLocation);

    if (mapComparisonTf != 0){
        //line 4920 entered below
        xTemp = xTemp + positionMod1;
        yTemp = yTemp + positionMod2;
        torpedoTracker1 = floor(xTemp + 0.5);
        torpedoTracker2 = floor(yTemp + 0.5);
    }

    strcpy(tempObject,"+K+");
    tempObjectPos1 = xTemp;
    tempObjectPos2 = yTemp;
    //GOSUB 8830
    compareStringInArray(tempObject,tempObjectPos1,tempObjectPos2,objectLocation,mapComparisonTf,quadrantMap,objectLocation);

    if (mapComparisonTf == 0){
        //5210
    }
    printf("*** KLINGON DESTROYED ***\n");
    localKlingons = localKlingons - 1;
    totalKlingons = totalKlingons - 1;
    if (totalKlingons<= 0){
        //6370
    }

    for (i = 1; i <= 3; i++){
        if ((torpedoTracker1 == klingonData[i][1]) && (torpedoTracker2 == klingonData[i][2])){
            //5190 entered below
            klingonData[i][3] = 0;
            //GOTO 5430
        }
    }

    i = 3;
    klingonData[i][3] = 0;
    //GOTO 5430

    strcpy(tempObject," * ");
    tempObjectPos1 = xTemp;
    tempObjectPos2 = yTemp;
    //GOSUB 8830
    compareStringInArray(tempObject,tempObjectPos1,tempObjectPos2,objectLocation,mapComparisonTf,quadrantMap,objectLocation);

    if (mapComparisonTf == 0){
        strcpy(tempObject,">B<");
        tempObjectPos1 = xTemp;
        tempObjectPos2 = yTemp;
        //GOSUB 8830
        compareStringInArray(tempObject,tempObjectPos1,tempObjectPos2,objectLocation,mapComparisonTf,quadrantMap,objectLocation);

        if (mapComparisonTf == 0){
            //4760 entered below
            printf("PHOTON TORPEDO COURSE(1-9) ");
            scanf("%d", &courseDirectionInput);
            printf("\n");
            if (courseDirectionInput == 9)
            {
                courseDirectionInput == 1;
            }
        }

    }

    printf(" STAR AT %d, %d ABSORBED TORPEDO ENERGY\n", torpedoTracker1, torpedoTracker2);
    //GOSUB 6000
    shootKlingons();

    //GOTO 1990

    strcpy(tempObject,">B<");
    tempObjectPos1 = xTemp;
    tempObjectPos2 = yTemp;
    //GOSUB 8830
    compareStringInArray(tempObject,tempObjectPos1,tempObjectPos2,objectLocation,mapComparisonTf,quadrantMap,objectLocation);

    if (mapComparisonTf == 0){
        //4760 entered below
        printf("PHOTON TORPEDO COURSE(1-9) \n");
        scanf("%d", &courseDirectionInput);
        if (courseDirectionInput == 9)
        {
            courseDirectionInput = 1;
        }
    }

    printf("*** STARBASE DESTROYED***\n");
    localStarBases = localStarBases - 1;
    starBaseTotal = starBaseTotal - 1;
    if ((starBaseTotal > 0) || (totalKlingons > startStardate - currentStardate-daysRemaining)){
        printf("STARFLEET COMMAND REVIEWING YOUR RECORD TO CONSIDER \n");
        printf("COURT MATERIAL! \n");
    }
    printf("THAT DOES IT, CAPTIAON!! YOU ARE HEREBY RELIVED OF COMMAND \n");
    printf(" AND SENTENCED TO 99 STARDATES AT HARD LABOR ON CYGNUS 12\n");
    //GOTO 6270

    printf("STARFLEET COMMAND REVIEWING YOUR RECORD TO CONSIDER \n");
    printf("COURT MATERIAL! \n");
    starBaseShieldTf = 0;

    tempObjectPos1 = xTemp;
    tempObjectPos2 = yTemp;
    strcpy(tempObject,"   ");
    //GOSUB 8670
    enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);

    galaxyInfo[quadrant1][quadrant2] = localKlingons*100+localStarBases*10+localStars;
    tempInfo[quadrant1][quadrant2] = galaxyInfo[quadrant1][quadrant2];
    //GOSUB 6000
    shootKlingons();
    //GOTO 1990

    printf("TORPEDO MISSED \n");
    //GOSUB 6000
    shootKlingons();
    //GOTO 1990

//********End of Block 16********
//}
//{Block 17: Shield Controls                -MISSING GOTO 1990
                //BASIC lines 5520-5670
    ShieldControls(shipDamageArray, &currentEnergy, &currentShield);
    //GOTO 1990

//********End of Block 17********
//}
//{Block 18: Damage Control Report          MISSING GOTO'S, GOSUB'S, LEFTMIDRIGHT
                //BASIC lines 5680-5980
    if (shipDamageArray[6] >= 0){
        //GOTO 5910
    }
    printf("DAMAGE CONTROL REPORT NOT AVAILABLE \n");
    if (starBaseShieldTf == 0){
        //GOTO 1990
    }

    repairTime = 0;
    for (i = 1; i <= 8; i++){
        if(shipDamageArray[i] == 1){
            repairTime = repairTime + 0.1;
        }
    }

    if (repairTime == 0){
        //GOTO 1990
    }
    printf("\n"); //print :
    repairTime = repairTime + quadrantDamageMod;
    if (repairTime >= 1){
        repairTime = 0.9;
    }

    printf("TECHNICIANS STANDING BY TO EFFECT REPAIRS TO YOUR SHIP;\n");
    printf("ESTIMATED TIME TO REPAIR: %d STARDATES \n", 100*(int) 100*repairTime);
    printf("WILL YOU AUTHORIZE THE REPAIR ORDER (Y/N)?");
    scanf("%c", &tempObject);
    printf("\n");

    if (tempObject != 'y'){
        //GOTO 1990
    }
    for (i = 1; i <= 8; i++){
        if (shipDamageArray[i] < 0){
            shipDamageArray[i] = 0;
        }
    }
    startStardate = startStardate + repairTime+ 0.1;
    printf("\n");
    printf("DEVICE            STATE OF REPAIR\n");
    for (shipPartInt = 1; shipPartInt <= 8; shipPartInt++){
        //GOSUB 8790
        printDeviceName(shipPartInt,shipPartName);
        //PRINTG2$;LEFT$(Z$,25-LEN(G2$)); INT(D(R1)*100)*.01
        printf("%s", shipPartName);
        printf("%s", parseLEFT(spacingSpace,25-strlen(shipPartName)));
        printf("%d", floor((shipDamageArray[shipPartInt]*100)*0.01));
    }
    printf("/n");
    if (starBaseShieldTf != 0){  //5720 entered below
        repairTime = 0;
        for (i = 1; i <= 8; i++){
            if(shipDamageArray[i] == 1){
                repairTime = repairTime + 0.1;
            }
        }
    }
    //GOTO 1990

//********End of Block 18********
//}
//{Block 19: Klingons Firing                MISSING GOTO'S, GOSUB'S
                //BASIC lines 5990-6200
    if (localKlingons <= 0){
        return;
    }
    if (starBaseShieldTf != 0){
        printf("STARBASE SHEILDS PROTECT THE ENTERPRISE \n");
        return;
    }

    for (i = 1; i <= 3; i++){
        if (klingonData[i][3] <= 0){
            //6200
        }
        random1=RndZeroToOne();
        enemyHit = floor( (klingonData[i][3] / phasorDamageMod(1)) * (2+random1));
        currentShield = currentShield - enemyHit;
        klingonData[i][3] = klingonData[i][3] / (3*random1);

        printf("%d UNIT HIT ON ENTERPRISE FROM SECTOR %d, %d \n", klingonData[i][1], klingonData[i][2]);
        if (currentShield <= 0){
            //6240
        }
        printf("   <SHIELDS DOWN TO %d UNITS \n", currentShield);
        if (enemyHit < 20){
            //6200
        }
        if ((RndZeroToOne()>0.6) || (enemyHit/currentShield <= 0.02)){
            //6200
        }
        shipPartInt = RndIntOneToEight();
        shipDamageArray[shipPartInt] =  shipDamageArray[shipPartInt]-enemyHit/currentShield-0.5*RndZeroToOne();
        //GOSUB 8790
        printDeviceName(shipPartInt,shipPartName);
        printf("DAMAGE CONTROL REPORTS %c DAMAGED BY THE HIT \n", shipPartName);
    }
    //RETURN

//********End of Block 19********
//}
//{Block 20: Game Over                      MISSING GOTO'S, GOSUB'S
                //BASIC lines 6210-6410
    printf("IT IS STARDATE %d\n", startStardate);
    //GOTO 6270

    printf("\n");
    printf("THE ENTERPRISE HAS BEEN DESTORYED. THE FEDERATION\n");
    printf("WILL BE CONQUERED \n");
    //GOTO 6220

    printf("THERE WERE %d KLINGON BATTLE CRUISERS LEFT AT\n", totalKlingons);
    printf("THE END OF YOUR MISSION");
    printf("\n"); //print :
    print("\n"); //print :

    if (starBaseTotal == 0){
        //GOTO 6360
    }

    printf("THE FEDERATION IS IN NEED OF A NEW STARSHIP COMMANDER \n");
    printf("FOR A SIMILAR MISSION -- IF THERE IS A VOLUNTEER \n");
    printf("\n LET HIM STEP FORWARD AND ENTER 'AYE' \n");
    scanf("%c", &tempObject);

    if ((tempObject == 'AYE') || (tempObject == 'Aye') || (tempObject == 'aye')){
        //10 //Restart game
    }
    return(0);

    printf("CONGRATULATIONS, CAPTAIN! THE LAST KLINGON BATTLE CRUISER\n");
    printf("MENACING THE FEDERATION HAS BEEN DESTROYED. \n");
    printf("\n");
    int efficencyRate = 1000*(startKlingons/(pow(startStardate - currentStardate, 2)));
    printf("YOUR EFFICIENCY RATING IS %d\n", efficencyRate);

//********End of Block 20********
//}
//{Block 21: SRS Scan, Danger State, Info   MISSING GOTO'S, GOSUB'S
                //BASIC lines 6420-7270
    for (i = sector1 - 1; i <= sector1 + 1; i++){
        for (j = sector2 - 1; j <= sector2 + 1; j++){
            if (((int)(i + 0.5) < 1) || ((int)(i + 0.5) > 8) || ((int) (j + 0.5) < 1) || ((int) (j + 0.5) > 8)){
                //GOTO 6540
            }
            strcpy(tempObject,">B<");
            tempObjectPos1 = i;
            tempObjectPos2 = j;
            //GOSUB 8830
            compareStringInArray(tempObject,tempObjectPos1,tempObjectPos2,objectLocation,mapComparisonTf,quadrantMap,objectLocation);

            if (mapComparisonTf == 1){
                //GOTO 6580
            }
        }
//6540
    }
    starBaseShieldTf = 0;
    //GOTO 6650
//6580
    starBaseShieldTf = 1;
    strcpy(shipCondition,"DOCKED");
    currentEnergy = maxEnergy;
    currentTorpedos = maxTorpedos;
    printf("SHIELDS DROPPED FOR DOCKING PURPOSES \n");

    currentShield = 0;
    //GOTO 6720
//6650
    if (localKlingons > 0){
        strcpy(shipCondition,"*RED*");
        //GOTO 6720
    }
    strcpy(shipCondition,"GREEN");
    if (currentEnergy < maxEnergy*0.1){
        strcpy(shipCondition,"YELLOW");
    }
//6720
    if (shipDamageArray[2]>=){
        //6770
    }
    printf("\n");
    printf("*** SHORT RANGE SENSORS ARE OUT ***\n");
    printf("\n");
    return;

    strcpy(spacingText,"---------------------------------");
    printf("%c\n", spacingText);
    for (i =1; i <= 8; i++){
        for (j = ((i-1)*24+1); j <=  ((i-1)*24+22); j+= 3){
            printf(" %s", parseMid(quadrantMap, j, 3));  //PRINT " ";MID$(Q$,J,3);

        }
        //ON i GOTO 6850,6900,6960,7020,7070,7120,7180,7240
        switch (i){
        case 1:
            //6850
            printf("        STARDATE           %d", (int) (startStardate*10)*0.01);
            //GOTO 7260
            printf("%c", spacingText);
            return;
        case 2:
            //6900
            printf("        CONDITION          %s", shipCondition );
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
            printf("        TOTAL ENERGY   %d", (int) currentEnergy+currentShield);
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
            printf("        KLINGONS REMAINING            %d", (int) totalKlingons);
        }
//7260
    }
    printf("%s\n", spacingText);
    return;

//********End of Block 21********
//}
//{Block 22: Library Computer               MISSING GOTO'S
                //BASIC lines 7280-7380
    if (shipDamageArray[8]<0){
        printf("COMPUTER DISABLED\n");
        //GOTO 1990
    }

    printf("COMPUTER ACTIVE AND AWAITING COMMAND: \n");
    scanf("%lf", &libInput);
    printf("\n");
    if (libInput < 0){
        //GOTO 1990
    }
    printf("\n");
//ON A+1 GOTO 7540,7900,8070,8500,8150,7400
    if (libInput + 1 == 1){
        //7540
        // INPUT "DO YOU WANT A HARDCOPY? IS THE TTY ON (Y/N) ";A$
        //break;
    }
    else if (libInput + 1 == 2){
        //7900
        printf("   STATUS REPORT : " );
        strcpy(sPluralize,"");
        if (totalKlingons > 1){
            strcpy(sPluralize, "S");
        }
    }
    else if (libInput + 1 == 3){
        //8070
        if (localKlingons <= 0){
            //4270
            printf("SCIENCE OFFICER SPOCK REPORTS  'SENSORS SHOW NO ENEMY SHIPS\n");
            printf("                                IN THIS QUADRANT'");
            //GOTO 1990
                 if (currentShield + currentEnergy > 10){
                    if ((currentEnergy > 10) || (shipDamageArray[7] == 0)){
                        //2060
                        printf("COMMAND: ");
                        scanf("%c", tempObject);
                    }
                }
        }
    }
    else if (libInput + 1 == 4){
        //8500
        if (localStarBases != 0){
            printf("FROM ENTERPRISE TO STARBASE : \n" );
            warpInput = starBaseSector1;
            //X = starBaseSector2; block 26
            // GOTO 8120
            tempTorpedoInitialCoord1 = sector1;
            tempTorpedoInitialCoord2 = sector2;
            //GOTO 8220
            tempTorpedoFinalCoord2 = tempTorpedoFinalCoord2 - tempTorpedoInitialCoord2;
            tempTorpedoInitialCoord2 = tempTorpedoInitialCoord1 - tempTorpedoFinalCoord1;
            if (tempTorpedoFinalCoord2 < 0){
                //8350
                if (tempTorpedoInitialCoord2 > 0){
                    tempTorpedoInitialCoord1 = 3;
                    //GOTO 8420
                    if (abs(tempTorpedoInitialCoord2) >= abs(tempTorpedoFinalCoord2)){
                        //8450
                        printf("DIRECTION =%d\n", tempTorpedoInitialCoord1+(abs(tempTorpedoFinalCoord2)+abs(tempTorpedoInitialCoord2)));

                    }
                }
            }
        }
    }
    else if (libInput + 1 == 5){
        //8150
        printf("DIRECTION/DISTANCE CALCULATOR : ");
        printf("YOU ARE AT QUADRANT %d, %d SECTOR %d, %d", quadrant1, quadrant2, sector1, sector2);
        printf("PLEASE ENTER\n");
        printf("INITIAL COODINATES (x,y)");
        scanf("%d %d", &tempTorpedoInitialCoord1, &tempTorpedoInitialCoord2);
        printf("\nFINAL COORDINATES (x,y)");
        scanf("%d %d", &tempTorpedoFinalCoord1, &tempTorpedoFinalCoord2);
    }
    else if (libInput + 1 == 6){
        //7400
        libMenu = 0;
        noNumberNamesTf = 1;
        printf("                        THE GALAXY\n");
        //GOTO 7550

    }
    else{
        //continue;
    }
    printf("FUNCTIONS AVAILABLE FROM LIBRARY-COMPUTER : \n");
    printf("   0 = CUMULATIVE GALACTIC RECORD\n");
    printf("   1 = STATUS REPORT\n");
    printf("   2 = PHOTON TORPEDO DATA\n");
    printf("   3 = STARBASE NAV DATA\n");
    printf("   4 = DIRECTION/DISTANCE CALCULATOR\n");
    printf("   5 = GALAXY 'REGION NAME' MAP\n");
    printf("\n");
    //GOTO 7320

//********End of Block 22********
//}
//{Block 23: Cum Gal Record to Galaxy Map   -COMPLETE, UNCOMPILED
                //BASIC lines 7390-7520
// SETUP TO CHANGE CUM GAL RECORD TO GALAXY MAP
    libMenu = 0;
    noNumberNamesTf = 1;
    printf("                        THE GALAXY\n");
    bool gotoSwitch7550=1;//GOTO 7550

//********End of Block 23********
//}
//{Block 24: Print Cum Gal Record           -MISSING GOTO 1990
                //BASIC lines 7530-7880
    if (gotoSwitch7550!=1){
        printf("\n");
        printf("\t");
        printf("\n COMPUTER RECORD OF GALAXY FOR QUADRANT  %d, %d\n", quadrant1, quadrant2);
        printf("\n");
    }
    gotoSwitch7550=0;
//7550
    printf("       1     2     3     4     5     6     7     8\n");
    strcpy(spacingText,"     ----- ----- ----- ----- ----- ----- ----- -----");
    printf("%c\n", spacingText);

    int gotoSwitch7850 = 0;
    for (i = 1; i <= 8; i++){
        print("%d  ", i);
        if(libMenu == 0){
            bool gotoSwitch7740 = 1;//GOTO 7740
        }
        if (gotoSwitch7740!=1){
            for (j = 1; j <= 8; j++){
                if (gotoSwitch7850!=1){
                    printf("   ");
                    if (tempInfo[i][j]==0){
                        printf("***");
                        gotoSwitch7850 = 1;//GOTO 7720->GOTO 7850
                    }
                    if (gotoSwitch7850 !=1){
                        printf("%s", parseRIGHT(strlen(tempInfo[i][j]+1000), 3)); //PRINT RIGHT$(STR$(Z(I,J)+1000),3);
                    }
                }
            }
//7720
            gotoSwitch7850 = 1;//GOTO 7850
        }
        gotoSwitch7740 = 0;
//7740
        if (gotoSwitch7850 !=1){
            quadrantName1 = i;
            quadrantName2 = 1;
            quadrantNameInArray(quadrantName1,quadrantName2,quadrantNameString,noNumberNamesTf);//GOSUB 9030

            printAdvance = floor(15-0.5*strlen(shipPartName));
            printf("%d %s\n", printAdvance, shipPartName); //TAB()?

            quadrantName2 = 5;
            quadrantNameInArray(quadrantName1,quadrantName2,quadrantNameString,noNumberNamesTf);//GOSUB 9030

            printAdvance = (int) (39-0.5*srtlen(shipPartName));
            printf("%d %c\n", printAdvance, shipPartName); //tab()?
        }
        gotoSwitch7850 = 0;
//7850
        printf("\n");
        printf("%c\n", spacingText);
    }
    //GOTO 1990

//********End of Block 24********
//}
//{Block 25: Status Report                  -NEED DamageControl, GOTO 1990
                //BASIC lines 7890-8050
StatusReport(starBaseTotal,totalKlingons,currentStardate,daysRemaining,startStardate,sPluralize);
//DamageControl()//GOTO 5690
//GOTO 1990

//********End of Block 25********
//}
//{Block 26: Split functions                MISSING GOTO'S, VERY INCOMPLETE
                //BASIC lines 8060-8570
//TORPEDO, BASE, NAV, D/D CALCULATOR
    if (localKlingons <= 0){
        printf("SCIENCE OFFICER SPOCK REPORTS  'SENSORS SHOW NO ENEMY SHIPS");//GOTO 4270
        printf("                                IN THIS QUADRANT'");
        //GOTO 1990
    }

    strcpy(sPluralize," ");
    if (localKlingons > 1){
        strcpy(sPluralize,"S");
    }
    printf("FROM ENTERPRISE TO KLINGON BATTLE CRUISER %c\n", sPluralize);
    libMenu = 0;
    for (int i = 1; i <= 3; i++){
        if (!(klingonData[i][3] <= 0)){ //IF K(I,3)<=0 THEN 8480
            warpInput = klingonData[i][1];
            inputX = klingonData[i][2];
            tempTorpedoInitialCoord1 = sector1;
            tempTorpedoInitialCoord2 = sector2;
            bool gotoSwitch8220 = 1;
            if (gotoSwitch8220 !=1){
                printf("DIRECTION/DISTANCE CALCULATOR : \n");
                printf("YOU ARE AT QUADRANT %d, %d SECTOR %d, %d\n", quadrant1, quadrant2, sector1, sector2);
                printf("PLEASE ENTER\n");
                printf("INITIAL COORDINATES (X,Y) ");
                scanf("%d %d", &tempTorpedoInitialCoord1, &tempTorpedoInitialCoord2);
                printf("\nFINAL COORDINATES (X,Y) ");
                scanf("%d %d", &tempTorpedoFinalCoord1, &tempTorpedoFinalCoord2);
                printf("\n");
            }
            gotoSwitch8220=0;
//8220
            tempTorpedoFinalCoord2 = tempTorpedoFinalCoord2 - tempTorpedoInitialCoord2;
            tempTorpedoInitialCoord2 = tempTorpedoInitialCoord1 - tempTorpedoFinalCoord1;

            if (tempTorpedoFinalCoord2 < 0){
                bool gotoSwitch8350 = 1; //8350
            }
            if (gotoSwitch8350 != 1){
                if (tempTorpedoInitialCoord2 < 0){
                    //8410
                }
                if (tempTorpedoFinalCoord2 > 0){
                    //8280
                }
                if (tempTorpedoInitialCoord2 == 0){
                    tempTorpedoInitialCoord1 = 5;
                    bool gotoSwitch8290 = 1;//GOTO 8290
                }
                if (gotoSwitch8290!=1){
//8280
                    tempTorpedoInitialCoord1 = 1;
                }
                gotoSwitch8290 = 0;
//8290
                if (abs(tempTorpedoInitialCoord2) <= abs(tempTorpedoFinalCoord2)){
                    //8330
                }
                printf("DIRECTION = %d\n ", tempTorpedoInitialCoord1+(((abs(tempTorpedoInitialCoord2)-abs(tempTorpedoFinalCoord2))+abs(tempTorpedoInitialCoord2))/abs(tempTorpedoFinalCoord2)));
                //GOTO 8460
                printf("DIRECTION = %d\n", tempTorpedoInitialCoord1+(abs(tempTorpedoInitialCoord2)/abs(tempTorpedoFinalCoord2)));
                //GOTO 8460
            }
            gotoSwitch8350 = 0;
//8350
            if (tempTorpedoInitialCoord2 > 0){
                tempTorpedoInitialCoord1 = 3;
                //GOTO 8420
            }

            if (tempTorpedoFinalCoord2 != 0){
                tempTorpedoInitialCoord1 = 5;
                //GOTO 8290
            }
//8410
            tempTorpedoInitialCoord1 = 7;
            if (abs(tempTorpedoInitialCoord2) >= abs(tempTorpedoFinalCoord2)){
                //8450
            }
        }
        printf("DIRECTION = %d\n", tempTorpedoInitialCoord1+(((abs(tempTorpedoFinalCoord2)-abs(tempTorpedoInitialCoord2))+abs(tempTorpedoFinalCoord2))/abs(tempTorpedoFinalCoord2)));
        //GOTO 8460

        printf("DIRECTION = %d\n", tempTorpedoInitialCoord1+(abs(tempTorpedoFinalCoord2)/abs(tempTorpedoInitialCoord2)));

        printf("DISTANCE = %f\n", sqrt(pow(tempTorpedoFinalCoord2, 2) + pow(tempTorpedoInitialCoord2, 2)));
        if (libMenu == 1){
            //1990
        }
    }
//8480
    //GOTO 1990

    if (localStarBases != 0){
        printf("FROM ENTERPRISE TO STARBASE : \n");
        tempTorpedoInitialCoord1 = starBaseSector1;
        tempTorpedoFinalCoord2 = starBaseSector2;
        //GOTO 8120
    }

    printf("MR. SPOCK REPORTS, ' SENSORS SHOW NO STARBASES IN THIS\n");
    printf(" QUADRANT.\n");
    //GOTO 1990

//********End of Block 26********
//}
//{Block 27: Find Empty Place in Quadrant   -MISSING SUB FUNCTIONALITY
                //BASIC lines 8580-8600
    emptyPlaceQuad(tempObject,tempObjectPos1,tempObjectPos2);//GOSUB 8590
    compareStringInArray(tempObject,tempObjectPos1,tempObjectPos2,objectLocation,mapComparisonTf,quadrantMap,objectLocation);//GOSUB 8830
    if (mapComparisonTf == 0){
        emptyPlaceQuad(tempObject,tempObjectPos1,tempObjectPos2);//GOSUB 8590
    }

//********End of Block 27********
//}
//{Block 28: Insert Ship into Map           -FUNCTION INCOMPLETE, LEFTMIDRIGHT
                //BASIC lines 8660-8770
//INSERT IN STRING ARRAY FOR QUADRANT
enterStringQuad(tempObject,tempObjectPos1,tempObjectPos2,quadrantMap,objectLocation,shipCondition);

//********End of Block 28********
//}
//{Block 29: Print Device Name              -COMPLETE, UNCOMPILED
                //BASIC lines 8780-8810
printDeviceName(shipPartInt,shipPartName);

//********End of Block 29********
//}
//{Block 30: String Comparison in QuadArray -MISSING LEFTMIDRIGHT
                //BASIC lines 8820-9000
compareStringInArray(tempObject, tempObjectPos1, tempObjectPos2, objectLocation, mapComparisonTf, quadrantMap, objectLocation);

//********End of Block 30********
//}
//{Block 31: Quadrant Name to Char Array    -COMPLETE, UNCOMPILED
                //BASIC lines 9010-9270
//9030
    quadrantNameInArray(quadrantName1,quadrantName2,quadrantNameString,noNumberNamesTf);

//********End of Block 31********
//}
/**/
}
